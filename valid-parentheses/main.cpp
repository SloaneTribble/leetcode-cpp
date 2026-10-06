#include <iostream>
#include <stack>
#include <string>

// https://leetcode.com/problems/valid-parentheses/description/?envType=problem-list-v2&envId=oizxjoit

/*
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
*/

bool isPair(char topOfStack, char current) {
    return (topOfStack == '(' && current == ')') ||
               (topOfStack == '{' && current == '}') ||
               (topOfStack == '[' && current == ']');
}

bool isValid(std::string s) {

        // remember to handle edge cases!
        if (s.length() < 2) return false;
        std::stack<char> chars;

        for (int i = 0; i < s.length(); i++) {
            char currentChar = s[i];

            switch (currentChar) {
                case '(':
                case '[':
                case '{':
                    chars.push(currentChar);
                    break;

                default:
                    if (chars.empty()) {
                        return false;
                    }
                    if (isPair(chars.top(), currentChar))
                        chars.pop();
                    else return false;
            }
        }

    // remember to handle edge cases!
    if (!chars.empty()) return false;

    return true;
}

int main() {
    std::cout << isValid("([)");
    return 0;
}
