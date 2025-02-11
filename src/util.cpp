#include "util.hpp"
#include <algorithm>

bool is_int(const std::string &s) {
    return !s.empty() && (s[0] == '-' || std::isdigit(s[0])) && std::all_of(std::next(s.begin()), s.end(), ::isdigit);
}