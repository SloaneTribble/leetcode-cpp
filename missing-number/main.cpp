#include <iostream>
#include <vector>

/*
 * https://leetcode.com/problems/missing-number/description/?envType=problem-list-v2&envId=oizxjoit
 * Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
 */


int missingNumber(std::vector<int>& nums) {
    // Numbers are in the range 0; there are n + 1 numbers in this range
    int n = nums.size() + 1;
    std::vector<bool> areTheyThere(n, false);

    for (int i = 0; i < nums.size(); i++) {
        int currentNum = nums[i];
        areTheyThere[currentNum] = true;
    }

    for (int i = 0; i < areTheyThere.size(); i++) {
        if (!areTheyThere[i]) {
            return i;
        }
    }

    // There should be a missing number, so we ought to never reach this
    return -1;
}


int main() {

    std::vector<int> ints = {3,0,1};
    int missing = missingNumber(ints);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
