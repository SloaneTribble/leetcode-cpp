#include <iostream>

/*
 * https://leetcode.com/problems/reverse-linked-list/description/?envType=problem-list-v2&envId=oizxjoit
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 */

// Intuition: If we have just one node, return it
// If there are exactly two nodes, switch them
// If there are more than two nodes, recursively call reverseList on all nodes but the first, then tack on the first to the end

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Old solution involved insertion -- too slow

// ListNode* insertNode(ListNode*head, ListNode* insertedNode) {
//     if (head == nullptr) {
//         return insertedNode;
//     }
//     if (head->next == nullptr) {
//         head->next = insertedNode;
//     } else {
//         insertNode(head->next, insertedNode);
//     }
//
//     return head;
// }

ListNode* reverseList(ListNode* head) {

    if (head == nullptr || head->next == nullptr) {
            return head;
        }

    if (head->next) {
        ListNode *current = head;
        head = head->next;
        ListNode *oldHead = head;
        head = reverseList(head);
        current->next = nullptr;
        oldHead->next = current;
    }

    return head;

}

ListNode* reverseListIterative(ListNode* head) {

    if (head->next == nullptr) {
        return head;
    }
    ListNode* prev = head;
    ListNode* curr = head;
    ListNode* next = head->next;

    // prev will be the new tail
    prev->next = nullptr;

    while (next != nullptr) {
        curr = next;
        next = curr->next;
        curr->next = prev;
        prev = curr;
    }

    return curr;
}

int main() {

    ListNode four(4);
    ListNode three(3, &four);
    ListNode two(2, &three);
    ListNode one(1, &two);


    ListNode* reversed = reverseListIterative(&one);
    return 0;
}
