#include <iostream>

// https://leetcode.com/problems/longest-palindromic-substring/description/
// Given a string s, return the longest palindromic substring in s.
// s consists only of digits and English letters.

std::string expandAroundCenter(int left, int right, int stringLength, std::string &s) {
    std::string currentPalindrome = "";

    while (left >= 0 && right < stringLength && s[left] == s[right]) {
        left--;
        right++;
    }

    currentPalindrome = s.substr(left + 1, right - left - 1);

    return currentPalindrome;
}



std::string longestPalindrome(std::string s) {
    std::string longestPalindrome = "";

    int stringLength = s.length();
    if (stringLength <= 1) {
        return s;
    }

    for (int i = 0; i < stringLength; i++) {
        std::string currentPalindromeEven = expandAroundCenter(i, i + 1, stringLength, s);

        std::string currentPalindromeOdd = expandAroundCenter(i, i, stringLength, s);

        std::string longerPalindromeOfTheTwo =
            currentPalindromeEven.length() > currentPalindromeOdd.length() ?
            currentPalindromeEven :
            currentPalindromeOdd;

        if (longerPalindromeOfTheTwo.length() > longestPalindrome.length()) {
            longestPalindrome = longerPalindromeOfTheTwo;
        }


    }
    return longestPalindrome;
}

int main() {

    std::cout << longestPalindrome("bb");


    return 0;
}
