#include "ariparser.hpp"
#include "util.hpp"
#include <algorithm>
#include <stdexcept>
#include <fstream>

std::string unescape(const std::string &s) {
    if (s.starts_with("|")) {
        return s.substr(1, s.length() - 2);
    } else {
        return s;
    }
}

ITS AriParser::parse(sexpresso::Sexp &s) {
    ITS its;
    for (unsigned i = 0; i < s.childCount(); ++i) {
        auto c {s.getChild(i)};
        auto fst {c.getChild(0)};
        auto str {fst.toString()};
        if (str == "entrypoint") {
            its.init = unescape(c.getChild(1).toString());
        } else if (str == "rule") {
            its.rules.push_back(parse_rule(c));
        }
    }
    return its;
}

Rule AriParser::parse_rule(sexpresso::Sexp &s) {
    Rule r;
    r.lhs = parse_lhs(s.getChild(1));
    r.rhs = parse_rhs(s.getChild(2));
    if (s.childCount() > 3) {
        r.cond = parse_formula(s.getChild(4));
    }
    return r;
}

Lhs AriParser::parse_lhs(sexpresso::Sexp &s) {
    Lhs lhs;
    lhs.location = unescape(s.getChild(0).toString());
    for (unsigned i = 1; i < s.childCount(); ++i) {
        lhs.args.push_back(unescape(s.getChild(i).toString()));
    }
    return lhs;
}

Rhs AriParser::parse_rhs(sexpresso::Sexp &s) {
    Rhs rhs;
    rhs.location = unescape(s.getChild(0).toString());
    for (unsigned i = 1; i < s.childCount(); ++i) {
        rhs.args.push_back(parse_expr(s.getChild(i)));
    }
    return rhs;
}

Formula AriParser::parse_formula(sexpresso::Sexp &s) {
    const auto fst {s.getChild(0).toString()};
    if (fst == "exists") {
        Exists ex;
        auto decls {s.getChild(1)};
        for (unsigned i = 0; i < decls.childCount(); ++i) {
            ex.vars.push_back(unescape(decls.getChild(i).getChild(0).str()));
        }
        ex.matrix = std::make_shared<Formula>(parse_formula(s.getChild(2)));
        return ex;
    } else if (fst == "and" || fst == "or") {
        BoolOp op;
        if (fst == "and") {
            op = BoolOp::And;
        } else if (fst == "or") {
            op = BoolOp::Or;
        } else {
            throw std::invalid_argument("unknown Boolean connection");
        }
        std::vector<Formula> args;
        for (unsigned i = 1; i < s.childCount(); ++i) {
            args.push_back(parse_formula(s.getChild(i)));
        }
        return Formula(BoolApp{op, args});
    } else {
        RelOp op;
        if (fst == "=") {
            op = RelOp::Eq;
        } else if (fst == "distinct") {
            op = RelOp::Neq;
        } else if (fst == ">=") {
            op = RelOp::Geq;
        } else if (fst == ">") {
            op = RelOp::Gt;
        } else if (fst == "<=") {
            op = RelOp::Leq;
        } else if (fst == "<") {
            op = RelOp::Lt;
        } else {
            throw std::invalid_argument("unknown relation");
        }
        return Formula(Rel{parse_expr(s.getChild(1)), op, parse_expr(s.getChild(2))});
    }
}

Expr AriParser::parse_expr(sexpresso::Sexp &s) {
    if (s.isString()) {
        const auto str {s.toString()};
        if (is_int(str)) {
            return Expr(stol(str));
        } else {
            return Expr(str);
        }
    }
    const auto fst {s.getChild(0).toString()};
    ArithOp op;
    if (fst == "+") {
        op = ArithOp::Plus;
    } else if (fst == "*") {
        op = ArithOp::Times;
    } else if (fst == "-") {
        if (s.childCount() == 2) {
            op = ArithOp::UnaryMinus;
        } else {
            op = ArithOp::Minus;
        }
    } else {
        throw std::invalid_argument("unknown arithmetic operator");
    }
    std::vector<Expr> args;
    for (unsigned i = 1; i < s.childCount(); ++i) {
        args.push_back(parse_expr(s.getChild(i)));
    }
    return Expr(ArithApp{op, args});
}

ITS AriParser::loadFromFile(const std::string &filename) {
    std::ifstream ifs(filename);
    std::string content(
        (std::istreambuf_iterator<char>(ifs)),
        (std::istreambuf_iterator<char>()));
    sexpresso::Sexp sexp = sexpresso::parse(content);
    AriParser parser;
    return parser.parse(sexp);
}
