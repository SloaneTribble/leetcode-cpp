#include <iostream>
#include <queue>

/*
 * https://leetcode.com/problems/invert-binary-tree/?envType=problem-list-v2&envId=oizxjoit
 * Given the root of a binary tree, invert the tree, and return its root.
 */

 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };

// Perform BFS -- for each node, switch its children, and add them to the queue

TreeNode* invertTree(TreeNode* root) {
    std::queue<TreeNode*> remainingNodes;

    // empty tree
    if (root == nullptr) {
        return root;
    }
    // trees with one node
    if (root->left == nullptr && root->right == nullptr) {
        return root;
    }

    remainingNodes.push(root);

    while (!remainingNodes.empty()) {
        TreeNode* current = remainingNodes.front();
        remainingNodes.pop();

        if (current->left != nullptr) {
            remainingNodes.push(current->left);
        }

        if (current->right != nullptr) {
            remainingNodes.push(current->right);
        }

        // swap the child nodes regardless of whether they're null
        TreeNode* left = current->left;
        TreeNode* right = current->right;

        current->left = right;
        current->right = left;
    }

    return root;
}

int main() {

    TreeNode* root = new TreeNode(
    1,
    new TreeNode(2),
    new TreeNode(3)
);

    TreeNode* root2 = new TreeNode(
    1,
    new TreeNode(2, new TreeNode(4), nullptr),
    new TreeNode(3, nullptr, new TreeNode(5))
);


    TreeNode* inverted = invertTree(root2);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
