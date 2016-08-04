/*
 * 237. Delete Node in a Linked List
 *
 * Write a function to delete a node (except the tail) in a singly linked list,
 * given only access to that node.
 *
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node
 * with value 3, the linked list should become 1 -> 2 -> 4 after calling your
 * function.
 */

/**
 * Definition for singly-linked list.
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node) {
            node->val = node->next->val;
            node->next = node->next->next;
        }
    }
};

int main(int argc, char *argv[])
{
    ListNode *p = new ListNode(1);
    ListNode *q = new ListNode(2);
    ListNode *x = new ListNode(3);
    ListNode *y = new ListNode(4);
    ListNode *k = NULL;

    p->next = q;
    q->next = x;
    x->next = y;

    k = p;
    while(k) {
       std::cout << k->val << std::endl; 
       k = k->next;
    }

    Solution *s = new Solution;
    s->deleteNode(x);

    k = p;
    while(k) {
       std::cout << k->val << std::endl; 
       k = k->next;
    }
    
    return 0;
}
