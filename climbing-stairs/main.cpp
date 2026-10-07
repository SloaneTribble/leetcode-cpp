#include <iostream>
#include <vector>

// https://leetcode.com/problems/climbing-stairs/description/?envType=problem-list-v2&envId=oizxjoit

/*
* You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

// Intuition: Memoization problem. Create an array ways, where ways[n] is the number of ways to reach the nth step of the staircase.
// ways[n+1] == ways[n-1] + ways[n-2]

/*
 * Base cases (and beyond):
 *  How many ways to reach...
 *  - step 0? 0
 *  - step 1? 1
 *  - step 2? 2 (2 steps, or 1 + 1 steps)
 *  - step 3? 3 (1 + 1 + 1, 1 + 2, 2 + 1) (ways[n - 1] + ways[n - 2])
 *  - step 4? 5 (1 + 1 + 1 + 1, 1 + 1 + 2, 1 + 2 + 1, 1 + 1 + 2, 2 + 2) (ways[n - 1] + ways[n - 2])
 */

int climbStairs(int n) {

    // handle base cases
    if (n <= 2) {
        return n;
    }
    // set up ways with base cases
    std::vector ways = {0, 1, 2};

    for (int i = 3; i <= n; i++) {
        ways.push_back(ways[i-2] + ways[i-1]);
    }

    return ways[n];
}

int main() {

    int ways = climbStairs(4);
    std::cout << ways << std::endl;

    return 0;
}
