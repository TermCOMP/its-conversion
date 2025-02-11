#include "KoatParseVisitor.h"
#include "its.hpp"

#include <any>

using relop_type = RelOp;
using fs_type = std::string;
using lhs_type = Lhs;
using com_type = std::vector<Rhs>;
using cond_type = Formula;
using rhs_type = Rhs;
using expr_type = Expr;
using var_type = std::string;
using lit_type = Rel;
using formula_type = Formula;

antlrcpp::Any KoatParseVisitor::visitMain(KoatParser::MainContext *ctx) {
    visitChildren(ctx);
    return its;
}

antlrcpp::Any KoatParseVisitor::visitGoal(KoatParser::GoalContext *ctx) {
    return {};
}

antlrcpp::Any KoatParseVisitor::visitStart(KoatParser::StartContext *ctx) {
    its.init = std::any_cast<fs_type>(visit(ctx->fs()));
    return {};
}

antlrcpp::Any KoatParseVisitor::visitSink(KoatParser::SinkContext *ctx) {
    its.init = std::any_cast<fs_type>(visit(ctx->fs()));
    return {};
}

antlrcpp::Any KoatParseVisitor::visitVardecl(KoatParser::VardeclContext *ctx) {
    return {};
}

antlrcpp::Any KoatParseVisitor::visitTranss(KoatParser::TranssContext *ctx) {
    visitChildren(ctx);
    return {};
}

antlrcpp::Any KoatParseVisitor::visitVar(KoatParser::VarContext *ctx) {
    return ctx->getText();
}

antlrcpp::Any KoatParseVisitor::visitFs(KoatParser::FsContext *ctx) {
    return ctx->getText();
}

antlrcpp::Any KoatParseVisitor::visitTrans(KoatParser::TransContext *ctx) {
    Rule r;
    r.lhs = std::any_cast<lhs_type>(visit(ctx->lhs()));
    const auto rhss = std::any_cast<com_type>(visit(ctx->com()));
    if (rhss.size() > 1) {
        throw std::invalid_argument("Com-symbols are not supported");
    }
    r.rhs = rhss.front();
    r.cond = std::make_shared<BoolApp>(BoolOp::And, std::vector<Formula>{});
    if (ctx->cond()) {
        r.cond = std::any_cast<cond_type>(visit(ctx->cond()));
    }
    std::set<std::string> bound_vars {r.lhs.args.begin(), r.lhs.args.end()};
    for (const auto &arg: r.rhs.args) {
        collect_vars(arg, bound_vars);
    }
    std::set<std::string> cond_vars;
    collect_vars(r.cond, cond_vars);
    Exists ex;
    for (const auto &x: cond_vars) {
        if (!bound_vars.contains(x)) {
            ex.vars.push_back(x);
        }
    }
    if (!ex.vars.empty()) {
        ex.matrix = std::make_shared<Formula>(r.cond);
        r.cond = ex;
    }
    its.rules.push_back(r);
    return {};
}

antlrcpp::Any KoatParseVisitor::visitLhs(KoatParser::LhsContext *ctx) {
    Lhs lhs;
    for (const auto& c: ctx->var()) {
        lhs.args.push_back(std::any_cast<var_type>(visit(c)));

    }
    lhs.location = std::any_cast<fs_type>(visit(ctx->fs()));
    return lhs;
}

antlrcpp::Any KoatParseVisitor::visitCom(KoatParser::ComContext *ctx) {
    com_type rhss;
    for (const auto &rhs: ctx->rhs()) {
        rhss.push_back(std::any_cast<rhs_type>(visit(rhs)));
    }
    return rhss;
}

antlrcpp::Any KoatParseVisitor::visitRhs(KoatParser::RhsContext *ctx) {
    Rhs rhs;
    for (const auto &c: ctx->expr()) {
        rhs.args.push_back(std::any_cast<expr_type>(visit(c)));
    }
    rhs.location = std::any_cast<fs_type>(visit(ctx->fs()));
    return rhs;
}

antlrcpp::Any KoatParseVisitor::visitTo(KoatParser::ToContext *ctx) {
    return {};
}

antlrcpp::Any KoatParseVisitor::visitLb(KoatParser::LbContext *ctx) {
    return {};
}

antlrcpp::Any KoatParseVisitor::visitUb(KoatParser::UbContext *ctx) {
    return {};
}

antlrcpp::Any KoatParseVisitor::visitCond(KoatParser::CondContext *ctx) {
    return visit(ctx->formula());
}

antlrcpp::Any KoatParseVisitor::visitExpr(KoatParser::ExprContext *ctx) {
    if (ctx->INT()) {
        return expr_type(std::stol(ctx->INT()->getText()));
    } else if (ctx->var()) {
        return expr_type(std::any_cast<var_type>(visit(ctx->var())));
    } else if (ctx->LPAR()) {
        return visit(ctx->expr(0));
    } else if (ctx->MINUS()) {
        if (ctx->expr().size() == 2) {
            const auto arg1 = std::any_cast<expr_type>(visit(ctx->expr(0)));
            const auto arg2 = std::any_cast<expr_type>(visit(ctx->expr(1)));
            return expr_type(std::make_shared<ArithApp>(ArithOp::Minus, std::vector{arg1, arg2}));
        } else {
            const auto res = std::any_cast<expr_type>(visit(ctx->expr(0)));
            return expr_type(std::make_shared<ArithApp>(ArithOp::UnaryMinus, std::vector{res}));
        }
    } else {
        const auto arg1 = std::any_cast<expr_type>(visit(ctx->expr(0)));
        const auto arg2 = std::any_cast<expr_type>(visit(ctx->expr(1)));
        if (ctx->TIMES()) {
            return expr_type(std::make_shared<ArithApp>(ArithOp::Times, std::vector{arg1, arg2}));
        } else if (ctx->PLUS()) {
            return expr_type(std::make_shared<ArithApp>(ArithOp::Plus, std::vector{arg1, arg2}));
        } else if (ctx->EXP()) {
            if (std::holds_alternative<long>(arg2)) {
                const auto exponent {std::get<long>(arg2)};
                std::vector<expr_type> args;
                for (long i = 0; i < exponent; ++i) {
                    args.push_back(arg1);
                }
                return expr_type(std::make_shared<ArithApp>(ArithOp::Times, args));
            }
        }
    }
    throw std::invalid_argument("failed to parse expression " + ctx->getText());
}

antlrcpp::Any KoatParseVisitor::visitFormula(KoatParser::FormulaContext *ctx) {
    if (ctx->lit()) {
        return formula_type(std::any_cast<lit_type>(visit(ctx->lit())));
    } else if (ctx->LPAR()) {
        return visit(ctx->formula(0));
    } else {
        const auto arg1 = std::any_cast<formula_type>(visit(ctx->formula(0)));
        const auto arg2 = std::any_cast<formula_type>(visit(ctx->formula(1)));
        if (ctx->AND()) {
            return formula_type(std::make_shared<BoolApp>(BoolOp::And, std::vector{arg1, arg2}));
        } else if (ctx->OR()) {
            return formula_type(std::make_shared<BoolApp>(BoolOp::Or, std::vector{arg1, arg2}));
        }
    }
    throw std::invalid_argument("failed to parse formula " + ctx->getText());
}

antlrcpp::Any KoatParseVisitor::visitLit(KoatParser::LitContext *ctx) {
    const auto &children = ctx->children;
    if (children.size() != 3) {
        throw std::invalid_argument("expected relation: " + ctx->getText());
    }
    const auto arg1 = std::any_cast<expr_type>(visit(ctx->expr(0)));
    const auto op = std::any_cast<relop_type>(visit(children[1]));
    const auto arg2 = std::any_cast<expr_type>(visit(ctx->expr(1)));
    return Rel{arg1, op, arg2};
}

antlrcpp::Any KoatParseVisitor::visitRelop(KoatParser::RelopContext *ctx) {
    if (ctx->LT()) {
        return relop_type::Lt;
    } else if (ctx->LEQ()) {
        return relop_type::Leq;
    } else if (ctx->EQ()) {
        return relop_type::Eq;
    } else if (ctx->GEQ()) {
        return relop_type::Geq;
    } else if (ctx->GT()) {
        return relop_type::Gt;
    } else if (ctx->NEQ()) {
        return relop_type::Neq;
    } else {
        throw std::invalid_argument("unknown relation: " + ctx->getText());
    }
}
