#include <iostream>
#include <unordered_map>
#include <vector>

/*
 * https://leetcode.com/problems/contains-duplicate/description/?envType=problem-list-v2&envId=oizxjoit
 * Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
 */

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_map<int, int> intCollection;

    for (int i = 0; i < nums.size(); i++) {
        int currentNumber = nums[i];
        if (intCollection.find(currentNumber) != intCollection.end()) {
            return true;
        }
        intCollection[currentNumber] = i;
    }

    return false;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
