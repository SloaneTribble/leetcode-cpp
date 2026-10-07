#include <iostream>

// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=problem-list-v2&envId=oizxjoit

/*
* Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

int maxDepth(TreeNode* root) {

    // base case
    if (root == nullptr) {
        return 0;
    }

    int maxLeft = 1 + maxDepth(root->left);

    int maxRight = 1 + maxDepth(root->right);

    return std::max(maxLeft, maxRight);
}

int main() {

    TreeNode *tree =
    new TreeNode(1,
        new TreeNode(2),
        new TreeNode(3)
    );

    TreeNode *tree2 =
    new TreeNode(1,
        new TreeNode(2,
            new TreeNode(4),
            nullptr
        ),
        new TreeNode(3,
            nullptr,
            new TreeNode(5,
                nullptr,
                new TreeNode(6)
            )
        )
    );

    std::cout << maxDepth(tree2) << std::endl;
    return 0;
}
