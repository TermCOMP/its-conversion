#include "parser.hpp"
#include "util.hpp"

#include <fstream>
#include <boost/algorithm/string.hpp>
#include <iostream>

namespace sexpressionparser {

    typedef Parser Self;

    ITS Self::loadFromFile(const std::string &filename) {
        Parser parser;
        parser.run(filename);
        return parser.res;
    }

    void Self::run(const std::string &filename) {
        std::ifstream ifs(filename);
        std::string content(
                (std::istreambuf_iterator<char>(ifs)),
                (std::istreambuf_iterator<char>()));
        sexpresso::Sexp sexp = sexpresso::parse(content);
        for (auto &ex: sexp.arguments()) {
            if (ex[0].str() == "define-fun") {
                if (ex[1].str() == "init_main") {
                    // the initial state
                    sexpresso::Sexp &init = ex[4];
                    // we do not support conditions regarding the initial state
                    assert(init[3].str() == "true");
                    res.init = init[2].str();
                } else if (ex[1].value.str == "next_main") {
                    std::vector<std::string> pre_vars;
                    std::vector<Expr> post_vars;
                    sexpresso::Sexp &scope = ex[2];
                    bool pre {true};
                    for (sexpresso::Sexp &e: scope.arguments()) {
                        if (e[1].str() == "Int") {
                            if (pre) {
                                pre_vars.push_back(e[0].str());
                            } else {
                                post_vars.push_back(Expr(e[0].str()));
                            }
                        } else if (e[1].str() == "Loc") {
                            assert(pre);
                            pre = false;
                        }
                    }
                    assert(pre_vars.size() == post_vars.size());
                    sexpresso::Sexp ruleExps = ex[4];
                    for (auto &ruleExp: ruleExps.arguments()) {
                        if (ruleExp[0].str() == "cfg_trans2") {
                            Lhs lhs;
                            Rhs rhs;
                            lhs.location = ruleExp[2].str();
                            lhs.args = pre_vars;
                            rhs.location = ruleExp[4].str();
                            rhs.args = post_vars;
                            const auto cond {parseCond(ruleExp[5])};
                            const auto rule {Rule(lhs, rhs, cond)};
                            res.rules.push_back(rule);
                        }
                    }
                }
            }
        }
    }

    Formula Self::parseCond(sexpresso::Sexp &sexp) {
        if (sexp.isString()) {
            if (sexp.str() == "false") {
                return Formula(std::make_shared<BoolApp>(BoolOp::Or, std::vector<Formula>{}));
            } else {
                assert(sexp.str() == "true");
                return Formula(std::make_shared<BoolApp>(BoolOp::And, std::vector<Formula>{}));
            }
        }
        const std::string op = sexp[0].str();
        if (op == "and") {
            std::vector<Formula> args;
            for (unsigned int i = 1; i < sexp.childCount(); i++) {
                args.push_back(parseCond(sexp[i]));
            }
            return Formula(std::make_shared<BoolApp>(BoolOp::And, args));
        } else if (op == "exists") {
            sexpresso::Sexp scope = sexp[1];
            Exists ex;
            for (unsigned i = 0; i < scope.childCount(); ++i) {
                ex.vars.push_back(scope[i][0].str());
            }
            ex.matrix = std::make_shared<Formula>(parseCond(sexp[2]));
            return ex;
        } else {
            return parseConstraint(sexp);
        }

    }

    Formula Self::parseConstraint(sexpresso::Sexp &sexp) {
        if (sexp.childCount() == 2) {
            assert(sexp[0].str() == "not");
            return Formula(std::make_shared<BoolApp>(BoolOp::Not, std::vector{parseConstraint(sexp[1])}));
        }
        assert(sexp.childCount() == 3);
        const std::string &op {sexp[0].str()};
        const auto fst {parseExpression(sexp[1])};
        const auto snd {parseExpression(sexp[2])};
        RelOp rop;
        if (op == "<=") {
            rop = RelOp::Leq;
        } else if (sexp[0].str() == "<") {
            rop = RelOp::Lt;
        } else if (sexp[0].str() == ">=") {
            rop = RelOp::Geq;
        } else if (sexp[0].str() == ">") {
            rop = RelOp::Gt;
        } else if (sexp[0].str() == "=") {
            rop = RelOp::Eq;
        } else {
            throw std::invalid_argument("unknown relation");
        }
        return Formula(Rel{fst, rop, snd});
    }

    Expr Self::parseExpression(sexpresso::Sexp &sexp) {
        if (sexp.childCount() == 1) {
            const auto &str {sexp.str()};
            if (is_int(str)) {
                return Expr(stol(str));
            } else {
                return Expr(str);
            }
        }
        const auto &op {sexp[0].str()};
        const auto fst {parseExpression(sexp[1])};
        if (sexp.childCount() == 3) {
            const auto snd {parseExpression(sexp[2])};
            ArithOp aop;
            if (op == "+") {
                aop = ArithOp::Plus;
            } else if (op == "-") {
                aop = ArithOp::Minus;
            } else if (op == "*") {
                aop = ArithOp::Times;
            } else {
                throw std::invalid_argument("unknown arithmetic operator");
            }
            return Expr(std::make_shared<ArithApp>(aop, std::vector{fst, snd}));
        } else if (sexp.childCount() == 2) {
            assert(op == "-");
            return Expr(std::make_shared<ArithApp>(ArithOp::UnaryMinus, std::vector{fst}));
        }
        throw std::invalid_argument("unknown operator");
    }

}
