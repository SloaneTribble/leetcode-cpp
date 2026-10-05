#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/container-with-most-water/?envType=problem-list-v2&envId=two-pointers

class Solution {
public:
    int maxArea(vector<int>& height) {
        // set one pointer on either side of << height >>
        int vectorLength = height.size();

        int left = 0;
        int right = vectorLength - 1;
        int maxArea = 0;

        while (left <= right) {
        // at each iteration, calculate the area of the container formed by the two pointers
            int currentHeight = min(height[left], height[right]);
            int currentWidth = right - left;
            int currentArea = currentHeight * currentWidth;

            maxArea = max(maxArea, currentArea);

            // pointers should move inward to eliminate the shorter of the two current heights
            if (height[left] < height[right]) {
                left++;
            } else if (height[right] < height[left]) {
                right--;
            }
            else {
                // got to keep moving one way or another --
                // may be better here to move a pointer to whichever of the two next heights is larger
                left++;
                right--;
            }

        }

    return maxArea;
    }
};

int main() {

    vector<int> testCase = {2, 1, 8, 6, 4, 6, 5, 5};
    vector<int> testCase2 = {0,0,0,10,0,10,0};

    Solution s;

    int testArea = s.maxArea(testCase);
    cout << testArea << endl;
    return 0;
}