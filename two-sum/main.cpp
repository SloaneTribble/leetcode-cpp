#include <vector>
#include <unordered_map>

// https://leetcode.com/problems/two-sum/description/?envType=problem-list-v2&envId=oizxjoit

/*
* You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
 */

// assuming that the solution must contain two indices

std::vector<int> twoSum(std::vector<int>& nums, int target) {

    // key = a value within nums; value: the index of that value
    std::unordered_map<int, int> valueAtIndex;

    for (int i = 0; i < nums.size(); i++) {
        // check the current value
        int currentValue = nums[i];

        // find out how much more we need to reach the target
        int remaining = target - currentValue;

        if (valueAtIndex.find(remaining) != valueAtIndex.end()) {
            return {i, valueAtIndex[remaining]};
        }

        valueAtIndex[currentValue] = i;
    }
    return {};
}

int main() {
    std::vector<int> testNums = {3,2,4};
    std::vector<int> testSolution = twoSum(testNums, 6);
    // output should be [1,2]
    return 0;
}
