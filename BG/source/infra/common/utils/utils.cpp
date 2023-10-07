#include "utils.h"

#include <string>
#include <sstream>
namespace BG
{
    BGString Utils::toCamelCase(const BGString& str)
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

    BGVector<BGString> Utils::splitString(const BGString& s, char delim)
    {
        BGVector<BGString> tokens;
        std::stringstream ss(s);
        BGString token;
        while (getline(ss, token, delim)) {
            tokens.push_back(token);
        }
        return tokens;
    }
}