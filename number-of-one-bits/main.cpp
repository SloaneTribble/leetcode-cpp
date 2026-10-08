#include <iostream>

/*
 * https://leetcode.com/problems/number-of-1-bits/description/?envType=problem-list-v2&envId=oizxjoit
 * Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).
 */

int hammingWeight(int n) {
    int weight = 0;
    while (n > 0) {
        int bit = n % 2;
        if (bit) {
            weight++;
        }
        n /= 2;
    }
    return weight;
}

int main() {
    std::cout << hammingWeight(2147483645) << std::endl;
    return 0;
}
