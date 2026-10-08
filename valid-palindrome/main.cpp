#include <iostream>
#include <string>
#include <algorithm>

/*
 * https://leetcode.com/problems/valid-palindrome/description/?envType=problem-list-v2&envId=oizxjoit
*
* A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
 */

// Remove all non-alphanumeric characters; convert uppercase letters to lower

bool isNotAlNum(char c) {
    if (std::isalnum(c) == 0) {
        return true;
    }

    // it IS an alphanumeric char
    return false;
}

bool isPalindrome(std::string s) {

    // remove non-alphanumeric characters
    s.erase(std::remove_if(s.begin(), s.end(), isNotAlNum), s.end());

    if (s.length() <= 1) {
        return true;
    }

    // convert uppercase letters to lower
    for (auto& x : s) {
        x = tolower(x);
    }

    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }


    return true;
}

int main() {
    std::cout << isPalindrome("A man, a plan, a canal: Panama") << std::endl;
    return 0;
}
