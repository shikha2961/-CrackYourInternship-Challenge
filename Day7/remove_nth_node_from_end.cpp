Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* temp = head;
        while(n>1){
            temp = temp->next;
            n--;
        }
        ListNode* chk = head;
        ListNode* pre = head;
        while(temp->next!=NULL){
            temp = temp->next;
                pre = chk;
            chk = chk->next;
        }
        if(chk==head){
            head = head->next;
            return head;
        }
        pre->next = chk->next;
        delete chk;
        return head;
    }
};
