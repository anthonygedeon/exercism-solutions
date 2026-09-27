#include "reverse_string.h"
#include <algorithm>

namespace reverse_string {

  std::string reverse_string(const std::string& s)
  {
    std::string result;
    std::reverse_copy(s.begin(), s.end(), std::back_inserter(result));
    return result;
  }

}  // namespace reverse_string
