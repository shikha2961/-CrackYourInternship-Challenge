// Problem: https://leetcode.com/problems/reverse-linked-list/
/*

Approach: To reverse a linked list, we have to just reverse the sign of directions in linked list
and Instead, NULL points to the last node, it should points to the first node.
  1. Create a dummy node, Initialize it with NULL and a Next node points to the just next to the head.
  2. While head is not equal to NULL, 
      connect next of head to the dummy
      Change now initialize dummy with head and head with next to change the next direction.
        
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = NULL;
        while(head!=NULL){
            ListNode* Next = head->next;
            head->next = dummy;
            dummy = head;
            head = Next;
        }
        return dummy;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

// Recursive way
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* Node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return Node;
    }
};
/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
