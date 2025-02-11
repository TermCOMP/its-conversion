#pragma once

#include <vector>
#include <variant>
#include <string>
#include <map>
#include <set>
#include <memory>

#include "sexpresso.hpp"

enum class ArithOp {
    Plus, Minus, Times, UnaryMinus
};

struct ArithApp;
using ArithAppPtr = std::shared_ptr<ArithApp>;

using Expr = std::variant<ArithAppPtr, long, std::string>;

sexpresso::Sexp to_sexp(const Expr &f);
std::string to_koat(const Expr &f);
void collect_vars(const Expr &f, std::set<std::string>& vars);

struct ArithApp {
    ArithOp op;
    std::vector<Expr> args;
};

enum class RelOp {
    Lt, Leq, Eq, Neq, Geq, Gt
};

struct Rel {
    Expr lhs;
    RelOp op;
    Expr rhs;
};

enum class BoolOp {
    And, Or, Not
};

struct BoolApp;
using BoolAppPtr = std::shared_ptr<BoolApp>;
struct Exists;

using Formula = std::variant<BoolAppPtr, Rel, Exists>;

sexpresso::Sexp to_sexp(const Formula &f);
std::string to_koat(const Formula &f);
void collect_vars(const Formula &f, std::set<std::string>& vars);

bool is_true(const Formula &f);

struct BoolApp {
    BoolOp op;
    std::vector<Formula> args;
};

struct Exists {
    std::vector<std::string> vars;
    std::shared_ptr<Formula> matrix;
};

struct Lhs {
    std::string location;
    std::vector<std::string> args;
};

struct Rhs {
    std::string location;
    std::vector<Expr> args;
};

struct Rule {
    Lhs lhs;
    Rhs rhs;
    Formula cond;
};

struct ITS {
    std::string init;
    std::vector<Rule> rules;

    std::map<std::string, unsigned> locations() const;
    std::set<std::string> vars() const;
    sexpresso::Sexp to_ari() const;
    sexpresso::Sexp to_its() const;
    std::string to_koat() const;

};
