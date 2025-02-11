#pragma once

#include "its.hpp"
#include "sexpresso.hpp"

class AriParser {

    ITS parse(sexpresso::Sexp &s);
    Rule parse_rule(sexpresso::Sexp &s);
    Lhs parse_lhs(sexpresso::Sexp &s);
    Rhs parse_rhs(sexpresso::Sexp &s);
    Formula parse_formula(sexpresso::Sexp &s);
    Expr parse_expr(sexpresso::Sexp &s);

public:

    static ITS loadFromFile(const std::string &filename);

};