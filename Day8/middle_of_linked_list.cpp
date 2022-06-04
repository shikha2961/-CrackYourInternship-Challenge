Problem: https://leetcode.com/problems/middle-of-the-linked-list/submissions/

Till Last pointer will be at the last position of the linked list, slow pointer will cover half of the linked list, the head of that half linked list, we want to return.
  
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

Time Complexity: O(N)
Space Complexity: O(1)
