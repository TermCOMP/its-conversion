#pragma once

#include "its.hpp"
#include "sexpresso.hpp"

namespace sexpressionparser {

    class Parser {

    public:
        static ITS loadFromFile(const std::string &filename);

    private:
        void run(const std::string &filename);

        Formula parseCond(sexpresso::Sexp &sexp);

        Formula parseConstraint(sexpresso::Sexp &sexp);

        Expr parseExpression(sexpresso::Sexp &sexp);

        ITS res;

    };

}

