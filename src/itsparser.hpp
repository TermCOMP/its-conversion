#pragma once

#include <string>

#include "its.hpp"

namespace parser {

class ITSParser {
public:

    static ITS loadFromFile(const std::string &path);

};

}
