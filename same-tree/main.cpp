#include <iostream>
#include <queue>

// https://leetcode.com/problems/same-tree/description/?envType=problem-list-v2&envId=oizxjoit

/*
* Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 */

// Conduct BFS on both trees; at each step, compare the current node at p with current node at q
// If we come across any mismatches, return false; return true after finishing BFS

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };



bool isSameTree(TreeNode* p, TreeNode* q) {

    if (p == nullptr && q != nullptr
        || p != nullptr && q == nullptr) {
        return false;
    }

    if (p == nullptr && q == nullptr) {
        return true;
    }
    if (p->val != q->val) {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}

int main() {

    TreeNode *tree =
    new TreeNode(1,
        new TreeNode(2),
        new TreeNode(3)
    );

    TreeNode *treeCopy =
    new TreeNode(1,
        new TreeNode(2),
        new TreeNode(3)
    );

    TreeNode *tree1 =
    new TreeNode(1,
        new TreeNode(2,
            new TreeNode(4),
            new TreeNode(5)
        ),
        new TreeNode(3,
            new TreeNode(6),
            new TreeNode(7)
        )
    );

    TreeNode *tree1copy =
    new TreeNode(1,
        new TreeNode(2,
            new TreeNode(4),
            new TreeNode(5)
        ),
        new TreeNode(3,
            new TreeNode(6),
            new TreeNode(7)
        )
    );

    TreeNode *tree2 =
    new TreeNode(1,
        new TreeNode(2,
            new TreeNode(4),
            nullptr
        ),
        new TreeNode(3,
            new TreeNode(6),
            new TreeNode(7)
        )
    );

    TreeNode *tree3 =
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

    std::cout << isSameTree(tree1, tree2) << std::endl;



    return 0;
}
