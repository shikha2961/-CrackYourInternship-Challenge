Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/


/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        if(head->val==head->next->val && head->next->next==NULL) return NULL;
        ListNode* dNode = new ListNode();
        dNode->next = head;
        ListNode* curr = dNode;
        int duplicate;
        while(curr->next && curr->next->next) {
            if(curr->next->val==curr->next->next->val){
                duplicate = curr->next->val;
                while(curr->next && curr->next->val==duplicate){
                    curr->next = curr->next->next;
                }
            }else{
                curr = curr->next;
            }
            
        }
        return dNode->next;
    }
};
