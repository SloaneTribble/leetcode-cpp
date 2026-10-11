#include <iostream>

/*
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/?envType=problem-list-v2&envId=oizxjoit
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 */

// Intuition: If head->next is null, then the current depth is 0. Otherwise, the depth is 1 + the depth of head->next.
// Use a helper function that gets called recursively on children of head to find the child at the appropriate depth.

// We need another pointer to keep track of the original head so we can return it once the list has been modified.


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// Find how far back a node is from the beginning of the list
// The first node in the list has a depth of 1
int getDepth(ListNode* head) {

    if (head->next == nullptr) {
        return 1;
    }

    return 1 + getDepth(head->next);
}

ListNode* removeNthFromEnd(ListNode* head, int n) {

    // edge case -- given a linked list of size one
    if (head->next == nullptr) {
        return nullptr;
    }

    int depth = getDepth(head);

    // We may need to remove the list tail
    if(depth == n) {
        return head->next;
    }

    // proceed down the list, then remove the node
    head->next = removeNthFromEnd(head->next, n);

    return head;

}

int main() {

    // ListNode fourth(4);
    // ListNode third(3, &fourth);
    ListNode second(2);
    ListNode first(1, &second);

    ListNode* updated = removeNthFromEnd(&first, 2);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
