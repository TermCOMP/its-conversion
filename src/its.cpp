#include "its.hpp"
#include <assert.h>
#include <iostream>
#include <set>
#include <cctype>
#include <algorithm>

std::set<char> ident_char {'~', '!', '@', '$', '%', '^', '&', '*', '_', '-', '+', '=', '<', '>', '.', '?', '/'};

std::set<std::string> ari_keywords {"fun", "rule", "format", "sort", "theory", "define-fun"};

bool is_ident_char(const char c) {
    return isdigit(c) || isalpha(c) || ident_char.contains(c);
}

bool is_identifier(const std::string &s) {
    return !s.empty() && !isdigit(s.front()) && !ari_keywords.contains(s) && std::all_of(s.begin(), s.end(), is_ident_char);
}

std::string escape(const std::string &s) {
    if (is_identifier(s)) {
        return s;
    } else {
        return "|" + s + "|";
    }
}

std::map<std::string, unsigned> ITS::locations() const {
    std::map<std::string, unsigned> res;
    for (const auto &r: rules) {
        assert(!r.lhs.location.empty());
        assert(!r.rhs.location.empty());
        res.emplace(r.lhs.location, r.lhs.args.size());
        res.emplace(r.rhs.location, r.rhs.args.size());
    }
    return res;
}

void collect_vars(const Formula &f, std::set<std::string> &vars) {
    if (std::holds_alternative<Rel>(f)) {
        const auto rel {std::get<Rel>(f)};
        collect_vars(rel.lhs, vars);
        collect_vars(rel.rhs, vars);
    } else if (std::holds_alternative<BoolApp>(f)) {
        const auto app {std::get<BoolApp>(f)};
        for (const auto &arg: app.args) {
            collect_vars(arg, vars);
        }
    }
}

void collect_vars(const Expr &f, std::set<std::string> &vars) {
    if (std::holds_alternative<std::string>(f)) {
        vars.insert(std::get<std::string>(f));
    } else if (std::holds_alternative<ArithApp>(f)) {
        const auto app {std::get<ArithApp>(f)};
        for (const auto &arg: app.args) {
            collect_vars(arg, vars);
        }
    }
}

std::set<std::string> ITS::vars() const {
    std::set<std::string> res;
    for (const auto &r: rules) {
        res.insert(r.lhs.args.begin(), r.lhs.args.end());
        for (const auto &arg: r.rhs.args) {
            collect_vars(arg, res);
        }
        collect_vars(r.cond, res);
    }
    return res;
}

sexpresso::Sexp ITS::to_its() const {
    sexpresso::Sexp res;
    res.addChild(sexpresso::parse("declare-sort Loc 0"));
    sexpresso::Sexp assert, distinct;
    distinct.addChild("distinct");
    for (const auto &[l,_]: locations()) {
        sexpresso::Sexp decl;
        decl.addChild("declare-const");
        decl.addChild(l);
        decl.addChild("Loc");
        res.addChild(decl);
        distinct.addChild(l);
    }
    assert.addChild("assert");
    assert.addChild(distinct);
    res.addChild(assert);
    res.addChild(sexpresso::parse("define-fun cfg_init ( (pc Loc) (src Loc) (rel Bool) ) Bool (and (= pc src) rel)"));
    res.addChild(sexpresso::parse("define-fun cfg_trans2 ( (pc Loc) (src Loc) (pc1 Loc) (dst Loc) (rel Bool) ) Bool (and (= pc src) (= pc1 dst) rel)"));
    res.addChild(sexpresso::parse("define-fun cfg_trans3 ( (pc Loc) (exit Loc) (pc1 Loc) (call Loc) (pc2 Loc) (return Loc) (rel Bool) ) Bool (and (= pc exit) (= pc1 call) (= pc2 return) rel)"));
    sexpresso::Sexp init, args, init_def;
    init.addChild("define-fun");
    init.addChild("init_main");
    args.addChild(sexpresso::parse("pc Loc"));
    for (const auto &x: rules.front().lhs.args) {
        sexpresso::Sexp decl;
        decl.addChild(x);
        decl.addChild("Int");
        args.addChild(decl);
    }
    init.addChild(args);
    init.addChild("Bool");
    init_def.addChild("cfg_init");
    init_def.addChild("pc");
    init_def.addChild(this->init);
    init_def.addChild("true");
    init.addChild(init_def);
    res.addChild(init);
    sexpresso::Sexp next;
    next.addChild("define-fun");
    next.addChild("next_main");
    args.addChild(sexpresso::parse("pc1 Loc"));
    for (const auto &x: rules.front().rhs.args) {
        sexpresso::Sexp decl;
        assert(std::holds_alternative<std::string>(x));
        decl.addChild(std::get<std::string>(x));
        decl.addChild("Int");
        args.addChild(decl);
    }
    next.addChild(args);
    next.addChild("Bool");
    sexpresso::Sexp disj;
    disj.addChild("or");
    for (const auto &r: rules) {
        for (const auto &x: r.rhs.args) {
            assert(std::holds_alternative<std::string>(x));
        }
        sexpresso::Sexp trans;
        trans.addChild("cfg_trans2");
        trans.addChild("pc");
        trans.addChild(r.lhs.location);
        trans.addChild("pc1");
        trans.addChild(r.rhs.location);
        trans.addChild(to_sexp(r.cond));
        disj.addChild(trans);
    }
    next.addChild(disj);
    res.addChild(next);
    return res;
}

sexpresso::Sexp ITS::to_ari() const {
    sexpresso::Sexp ari, format, theory, entrypoint;
    format.addChild("format");
    format.addChild("LCTRS");
    ari.addChild(format);
    theory.addChild("theory");
    theory.addChild("Ints");
    ari.addChild(theory);
    const auto locs {locations()};
    for (const auto &[f,arity]: locs) {
        sexpresso::Sexp decl, type;
        if (arity == 0) {
            type = sexpresso::Sexp("Int");
        } else {
            type.addChild("->");
            for (unsigned i = 0; i <= arity; ++i) {
                type.addChild("Int");
            }
        }
        decl.addChild("fun");
        decl.addChild(escape(f));
        decl.addChild(type);
        ari.addChild(decl);
    }
    entrypoint.addChild("entrypoint");
    entrypoint.addChild(init);
    ari.addChild(entrypoint);
    for (const auto &r: rules) {
        sexpresso::Sexp rule, lhs, rhs;
        lhs.addChild(escape(r.lhs.location));
        for (const auto &arg: r.lhs.args) {
            lhs.addChild(escape(arg));
        }
        rhs.addChild(escape(r.rhs.location));
        for (const auto &arg: r.rhs.args) {
            rhs.addChild(to_sexp(arg));
        }
        rule.addChild("rule");
        rule.addChild(lhs);
        rule.addChild(rhs);
        if (!is_true(r.cond)) {
            rule.addChild(":guard");
            rule.addChild(to_sexp(r.cond));
        }
        ari.addChild(rule);
    }
    return ari;
}

std::string ITS::to_koat() const {
    std::vector<std::string> lines;
    lines.push_back("(GOAL COMPLEXITY)");
    lines.push_back("(STARTTERM (FUNCTIONSYMBOLS " + init + "))");
    const auto vs {vars()};
    std::string decl {"(VAR"};
    for (const auto &v: vs) {
        decl += " " + v;
    }
    decl += ")";
    lines.push_back(decl);
    lines.push_back("(RULES");
    for (const auto &r: rules) {
        std::string s {"  "};
        s += r.lhs.location;
        s += "(";
        for (const auto &arg: r.lhs.args) {
            s += arg + ",";
        }
        s = s.substr(0, s.length() - 1);
        s += ") -> ";
        s += r.rhs.location;
        s += "(";
        for (const auto &arg: r.rhs.args) {
            s += ::to_koat(arg) + ",";
        }
        s = s.substr(0, s.length() - 1);
        s += ")";
        if (!is_true(r.cond)) {
            s += " :|: ";
            s += ::to_koat(r.cond);
        }
        lines.push_back(s);
    }
    lines.push_back(")");
    std::string res;
    for (const auto &s: lines) {
        res += s + '\n';
    }
    return res;
}

sexpresso::Sexp to_sexp(const Expr &f) {
    if (std::holds_alternative<long>(f)) {
        return sexpresso::Sexp(std::to_string(std::get<long>(f)));
    } else if (std::holds_alternative<std::string>(f)) {
        return sexpresso::Sexp(escape(std::get<std::string>(f)));
    } else {
        sexpresso::Sexp res;
        const auto app {std::get<ArithApp>(f)};
        switch (app.op) {
            case ArithOp::UnaryMinus:
            case ArithOp::Minus: res.addChild("-");
            break;
            case ArithOp::Plus: res.addChild("+");
            break;
            case ArithOp::Times: res.addChild("*");
            break;
        }
        for (const auto &arg: app.args) {
            res.addChild(to_sexp(arg));
        }
        return res;
    }
}

std::string to_koat(const Expr &f) {
    if (std::holds_alternative<long>(f)) {
        return std::to_string(std::get<long>(f));
    } else if (std::holds_alternative<std::string>(f)) {
        return std::get<std::string>(f);
    } else {
        std::string res;
        char op;
        const auto app {std::get<ArithApp>(f)};
        switch (app.op) {
            case ArithOp::UnaryMinus:
            assert(app.args.size() == 1);
            return "-" + ::to_koat(app.args.front());
            break;
            case ArithOp::Minus: op = '-';
            break;
            case ArithOp::Plus: op = '+';
            break;
            case ArithOp::Times: op = '*';
            break;
            default: throw std::invalid_argument("unknown arithmetic operator");
        }
        for (const auto &arg: app.args) {
            res += ::to_koat(arg) + ' ' + op + ' ';
        }
        res = res.substr(0, res.length() - 3);
        return res;
    }
}

bool is_true(const Formula &f) {
    if (std::holds_alternative<BoolApp>(f)) {
        const auto app {std::get<BoolApp>(f)};
        return app.op == BoolOp::And && app.args.empty();
    }
    return false;
}

sexpresso::Sexp to_sexp(const Formula &f) {
    sexpresso::Sexp res;
    if (std::holds_alternative<Rel>(f)) {
        const auto rel {std::get<Rel>(f)};
        switch (rel.op) {
            case RelOp::Eq: res.addChild("=");
            break;
            case RelOp::Geq: res.addChild(">=");
            break;
            case RelOp::Gt: res.addChild(">");
            break;
            case RelOp::Leq: res.addChild("<=");
            break;
            case RelOp::Lt: res.addChild("<");
            break;
            case RelOp::Neq: res.addChild("distinct");
            break;
        }
        res.addChild(to_sexp(rel.lhs));
        res.addChild(to_sexp(rel.rhs));
    } else if (std::holds_alternative<BoolApp>(f)) {
        const auto app {std::get<BoolApp>(f)};
        switch (app.op) {
            case BoolOp::And:
                if (app.args.empty()) {
                    return sexpresso::Sexp("true");
                }
                res.addChild("and");
                break;
            case BoolOp::Or:
                if (app.args.empty()) {
                    return sexpresso::Sexp("false");
                }
                res.addChild("or");
                break;
            case BoolOp::Not:
                res.addChild("not");
                break;
        }
        for (const auto &arg: app.args) {
            res.addChild(to_sexp(arg));
        }
    } else if (std::holds_alternative<Exists>(f)) {
        const auto ex {std::get<Exists>(f)};
        res.addChild("exists");
        sexpresso::Sexp decls;
        for (const auto &x: ex.vars) {
            sexpresso::Sexp decl;
            decl.addChild(x);
            decl.addChild("Int");
            decls.addChild(decl);
        }
        res.addChild(decls);
        res.addChild(to_sexp(*ex.matrix));
    } else {
        throw std::invalid_argument("unknown formula");
    }
    return res;
}

std::string to_koat(const Formula &f) {
    std::string res;
    std::string op;
    if (std::holds_alternative<Rel>(f)) {
        const auto rel {std::get<Rel>(f)};
        switch (rel.op) {
            case RelOp::Eq: op = "=";
            break;
            case RelOp::Geq: op = ">=";
            break;
            case RelOp::Gt: op = ">";
            break;
            case RelOp::Leq: op = "<=";
            break;
            case RelOp::Lt: op = "<";
            break;
            case RelOp::Neq: op = "!=";
            break;
        }
        return to_koat(rel.lhs) + op + to_koat(rel.rhs);
    } else if (std::holds_alternative<BoolApp>(f)) {
        const auto app {std::get<BoolApp>(f)};
        switch (app.op) {
            case BoolOp::And: op = "&&";
            break;
            case BoolOp::Or: op = "||";
            break;
            case BoolOp::Not: throw std::invalid_argument(".koat does not allow negation");
        }
        for (const auto &arg: app.args) {
            res += to_koat(arg) + " " + op + " ";
        }
        res = res.substr(0, res.size() - 4);
    } else if (std::holds_alternative<Exists>(f)) {
        return to_koat(*std::get<Exists>(f).matrix);
    } else {
        throw std::invalid_argument("unknown formula");
    }
    return res;
}
