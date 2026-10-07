#include <iostream>

// https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=problem-list-v2&envId=oizxjoit

/*
* You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
 */

// Using a loop: each iteration checks whether list1 or list2 have values, or if they are null
// As long as either list has a value, take the lowest value and place it as the next node in the new list
// once both list1 and list2 are null, return the head of the new list


// Lists are sorted in ascending order, with the heads containing the lowest values

// Provided definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode newListHead(0);
        ListNode *newList = &newListHead; // keep track of the head, because the other pointer will reach the tail of our new list

    // once either of the original lists is empty, the remaining values can all be spliced without comparison
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                newList->next = list1;
                list1 = list1->next;
            } else {
                newList->next = list2;
                list2 = list2->next;
            }
            // we don't want any of the other pieces of the bit of list we just merged onto our new one
            newList->next->next = nullptr;
            newList = newList->next;
        }

    // Check for any remaining values in either list

        if (list1 != nullptr) {
            newList->next = list1;
        }

        if (list2 != nullptr) {
            newList->next = list2;
        }

    return newListHead.next;
}


int main() {

    ListNode list1value3(4);
    ListNode list1value2(2, &list1value3);
    ListNode list1head(1, &list1value2);

    ListNode list2value3(4);
    ListNode list2value2(3, &list2value3);
    ListNode list2head(1, &list2value2);


    ListNode* solution = mergeTwoLists(&list1head, &list2head);

    while (solution !=nullptr) {
        std::cout << solution->val << std::endl;
        solution = solution->next;
    }

    return 0;
}
