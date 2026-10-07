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

bool hasEqualChildren(TreeNode* p, TreeNode* q) {
    if (p->left != nullptr && q->left == nullptr
    || p->left == nullptr && q->left != nullptr
    || p->right != nullptr && q->right == nullptr
    || p->right == nullptr && q->right != nullptr) {
        return false;
    }

    return true;
}

bool isSameTree(TreeNode* p, TreeNode* q) {

    // edge cases
    if (p == nullptr && q != nullptr
        || p != nullptr && q == nullptr) {
        return false;
    }

    if (p == nullptr && q ==nullptr) {
        return true;
    }
    std::queue<TreeNode *> nodeQueue;

    // we will try using one queue for both trees
    nodeQueue.push(p);
    nodeQueue.push(q);

    while (!nodeQueue.empty()) {

            TreeNode *pNode = nodeQueue.front();
            nodeQueue.pop();
            TreeNode *qNode = nodeQueue.front();
            nodeQueue.pop();


            if (pNode->val != qNode->val) {
                return false;
            }

            // make sure p and q have the same structure at the next level down
            if (!hasEqualChildren(pNode, qNode)) {
                return false;
            }

            if (pNode->left != nullptr) {
                nodeQueue.push(pNode->left);
                nodeQueue.push(qNode->left);
            }

            if (pNode->right != nullptr) {
                nodeQueue.push(pNode->right);
                nodeQueue.push(qNode->right);
            }
    }

    return true;


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

    std::cout << isSameTree(tree1, tree1copy) << std::endl;



    return 0;
}
