#include "utils.h"

BGString BG::Utils::toCamelCase(const BGString& str)
{
    BGString result;
    bool capitalizeNextChar = true;
    for (char c : str) {
        if (c == '_') {
            capitalizeNextChar = true;
        }
        else if (capitalizeNextChar) {
            result.push_back(std::toupper(c));
            capitalizeNextChar = false;
        }
        else {
            result.push_back(std::tolower(c));
        }
    }
    return result;
}
