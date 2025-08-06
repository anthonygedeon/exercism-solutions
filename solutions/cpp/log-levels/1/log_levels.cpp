#include <string>

namespace log_line {
std::string message(std::string line) {
    return line.substr(line.find(" ") + 1);
}

std::string log_level(std::string line) {
    size_t l{line.find("[") + 1};
    size_t r{line.find("]") - 1};
    return line.substr(l, r);
}

std::string reformat(std::string line) {
    return log_line::message(line) + " (" + log_line::log_level(line) + ")";
}
} // namespace log_line
