#include <iostream>
#include <set>

/*
 * https://leetcode.com/problems/linked-list-cycle/description/?envType=problem-list-v2&envId=oizxjoit
* Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
 */

// Use a set (or a hashmap with node addresses as keys and a dummy value)

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(nullptr) {}
     };

bool hasCycleSetSolution(ListNode *head) {
    std::set<ListNode*> visited;

    while (head != nullptr) {
        auto it = visited.find(head);
        if (it != visited.end()) {
            return true;
        }
        visited.insert(head);
        head = head->next;
    }

        return false;
}

bool hasCycleFloydsAlgo(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {

    ListNode first(3);
    ListNode second(2);
    ListNode third(0);
    ListNode fourth(-4);

    first.next = &second;
    second.next = &third;
    third.next = &fourth;
    fourth.next = &second;


    std::cout << hasCycleFloydsAlgo(&first) << std::endl;
    return 0;
}
