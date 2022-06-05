Problem: https://leetcode.com/problems/remove-linked-list-elements/

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL && head->val==val){
            head = head->next;
        }
        if(head==NULL) return NULL;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr!=NULL){
            while(curr!=NULL && curr->val==val){
                prev->next = curr->next;
                curr = prev->next;
            }
            if(curr==NULL) break;
            else{
                curr = curr->next;
                prev = prev->next;
            }
        }
        if(head->next==NULL && head->val==val) return NULL;
        return head;
    }
};
