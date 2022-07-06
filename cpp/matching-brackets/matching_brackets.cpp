#include "matching_brackets.h"
#include <string>
#include <deque>
#include <map>

namespace matching_brackets {
   bool check(const std::string& brackets) {

       std::map<char, char> brace{ 
           {']', '['}, 
           {'}', '{'}, 
           {')', '('}, 
       };

       std::deque<char> stack;
       for (char b : brackets) {
           switch(b) {
               case '[':
               case '(':
               case '{':
                   stack.push_back(b);
                   break;
               case ']':
               case ')':
               case '}':
                   if (!stack.empty()) {
                       if (brace.at(b) == stack.back()) {
                           stack.pop_back();
                       } else {
                           return false;
                       }
                   } 
                   break;
           }
       }
       return stack.empty();
   }
}  // namespace matching_brackets
