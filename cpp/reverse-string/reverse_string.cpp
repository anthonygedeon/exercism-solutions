#include "reverse_string.h"
#include <string>

namespace reverse_string {
   std::string reverse_string(const std::string& str) {
       if (str.empty()) return "";
       std::string result{""};
       for (int i {static_cast<int>(str.length()-1)}; i >= 0; i--) {
                result += str.at(i);
       }
       return result;
   }

}  // namespace reverse_string
