#include "itsparser.hpp"
#include "ariparser.hpp"
#include "sexpresso.hpp"
#include "parser.hpp"
#include <iostream>
#include <assert.h>

void print_help() {
    std::cout << "usage: its-conversion --to [ari|koat|smt2] $INPUT.[ari|koat|smt2]" << std::endl;
    exit(0);
}

int main(int argc, char *argv[]) {
    bool parse_to {false};
    std::string to, filename;
    for (int i = 0; i < argc; ++i) {
        if (parse_to) {
            to = argv[i];
            parse_to = false;
        } else if (strcmp(argv[i], "--to") == 0) {
            parse_to = true;
        } else if (strcmp(argv[i], "--help") == 0) {
            print_help();
        } else {
            filename = argv[i];
        }
    }
    if (filename.empty() || to.empty()) {
        print_help();
    }
    ITS its;
    if (filename.ends_with(".koat")) {
        its = parser::ITSParser::loadFromFile(filename);
    } else if (filename.ends_with(".ari")) {
        its = AriParser::loadFromFile(filename);
    } else if (filename.ends_with(".smt2")) {
        its = sexpressionparser::Parser::loadFromFile(filename);
    } else {
        std::cout << "unknown input format" << std::endl;
        print_help();
    }
    if (to == "ari") {
        auto ari{its.to_ari()};
        for (unsigned i = 0; i < ari.childCount(); ++i) {
            std::cout << ari.getChild(i).toCompactString() << std::endl;
        }
    } else if (to == "koat") {
        std::cout << its.to_koat();
    } else if (to == "smt2") {
        auto res{its.to_its()};
        for (unsigned i = 0; i < res.childCount(); ++i) {
            std::cout << res.getChild(i).toCompactString() << std::endl;
        }
    } else {
        std::cout << "unknown ouput format " << to << std::endl;
        print_help();
    }
}
