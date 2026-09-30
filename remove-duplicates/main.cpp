#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // if nums has 0 or 1 elements, then k must be 0 or 1
        if (nums.size() <= 1) {
            return nums.size();
        }
        int k = 1;
        int first = 0;
        int second = 1;
        int numberBeingComparedAgainst, otherNumber;

        while (second < nums.size()) {
            numberBeingComparedAgainst = nums[first];
            std::cout << "Now looking for numbers different from: " << numberBeingComparedAgainst << std::endl;
            otherNumber = nums[second];
            if (numberBeingComparedAgainst == otherNumber) {
                // found a duplicate, keep searching
                second++;
            }
            else {
                // there is another unique number in the vector
                std::cout << "New number found: " << otherNumber << std::endl;
                k++;
                first++;
                // now we'll start comparing against the new number
                nums[first] = otherNumber;
                // second continues a linear journey along the vector
                second++;
            }
        }
        return k;
    }

};

int main() {

    Solution sol;
    std::vector testVector = {0,0,1,1,1,2,2,3,3,4};
    int k = sol.removeDuplicates(testVector);
    std::cout << "Number of unique numbers in vector: " << k << std::endl;

    return 0;
}