Problem: https://leetcode.com/problems/palindrome-linked-list/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* temp = head;
        ListNode* pre = head;
        stack<int> s;
        int n=0;
        while(temp!=NULL){
            n++;
            temp = temp->next;
        }
        
        temp = head;
        int halfs = n/2;
        while(halfs--){
            temp = temp->next;
        }
        
        while(temp!=NULL){
            s.push(temp->val);
            temp=temp->next;
        }
       
        
        while(!s.empty()){
            if(s.top()!=pre->val) return false;
            pre = pre->next;
            s.pop();
        }
        return true;
    }
};
