#include "itsparser.hpp"
#include "KoatLexer.h"
#include "KoatParser.h"
#include "KoatParseVisitor.h"

using namespace antlr4;

using namespace parser;

ITS ITSParser::loadFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("Unable to open file: " + filename);
    }
    ANTLRInputStream input(file);
    KoatLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();
    KoatParser parser(&tokens);
    parser.setBuildParseTree(true);
    KoatParseVisitor vis;
    auto ctx = parser.main();
    if (parser.getNumberOfSyntaxErrors() > 0) {
        throw std::invalid_argument("parsing failed");
    } else {
        return std::any_cast<ITS>(vis.visit(ctx));
    }
}
