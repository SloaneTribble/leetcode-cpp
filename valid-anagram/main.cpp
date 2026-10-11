#include <iostream>
#include <unordered_map>
#include <string>

// https://leetcode.com/problems/valid-anagram/description/?envType=problem-list-v2&envId=oizxjoit
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Each string has an unordered map containing its letter frequencies
// Iterate through one map and compare its letter frequencies against those of the other map

std::unordered_map<char, int> populateMap(std::string s) {

    std::unordered_map<char, int> sMap;

    for (auto &ch : s) {
        if (sMap.find(ch) == sMap.end()) {
            sMap[ch] = 1;
        } else {
            sMap[ch] += 1;
        }
    }

    return sMap;
}

bool isAnagram(std::string s, std::string t) {

    if (s.length() != t.length()) {
        return false;
    }

    std::unordered_map<char, int> sMap = populateMap(s);
    std::unordered_map<char, int> tMap = populateMap(t);

    for (auto it : sMap) {
        char currentChar = it.first;
        int currentFrequency = it.second ;
        if (tMap[currentChar] != currentFrequency) {
            return false;
        }
    }

    return true;
}

int main() {

    bool anagramCheck = isAnagram("anagram", "nagaram");

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
