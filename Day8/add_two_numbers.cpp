Problem: https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* t1, ListNode* t2) {
        ListNode* h = new ListNode();
        ListNode* ans = h;
        int carry = 0,sum=0;
        while(t1 != NULL || t2!=NULL || carry){
            sum = 0;
            if(t1!=NULL){
                sum += t1->val;
                t1 = t1->next;
            }
             if(t2!=NULL){
                sum += t2->val;
                t2 = t2->next;
            }
            sum += carry;
             carry = sum/10;
             ListNode* newNode = new ListNode(sum%10);
            ans->next = newNode;
                ans = ans->next;
        }
        return h->next;
    }
};

