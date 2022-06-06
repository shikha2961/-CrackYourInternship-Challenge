Problem: https://leetcode.com/problems/reverse-linked-list-ii/

Appraoch1: (Brute Force)

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        while(left<=right){
            ListNode* temp1=head;
            ListNode* temp2=head;
            int l = left;
            while(l>1){
                temp1 = temp1->next;
                l--;
            }
            int r=right;
            while(r>1){
                temp2 = temp2->next;
                r--;
            }
            swap(temp1->val,temp2->val);
            left++;
            right--;
        }
        return head;
    }
};
