Problem Link: https://leetcode.com/problems/partition-list/

/*
TIme Complexity: O(N)
Space Complexity: O(1)
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL) return head;
            ListNode* temp = head;
            ListNode* first = new ListNode();
            ListNode* ans = first;
            ListNode* second = new ListNode();
            ListNode* notPerfect = second;
        while(temp!=NULL){
            if(temp->val<x){
                ListNode* newNode = new ListNode(temp->val);
                ans->next = newNode;
                ans = ans->next;
            }else{
                ListNode* newNode = new ListNode(temp->val);
                notPerfect->next = newNode;
                notPerfect = notPerfect->next;
            }
            temp = temp->next;
        }
        ans->next = second->next;
        return first->next;
    }
};
