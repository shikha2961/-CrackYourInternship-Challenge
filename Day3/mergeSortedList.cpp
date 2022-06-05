Problem: https://leetcode.com/problems/merge-two-sorted-lists/
Time Complexity: O(N)
Space complexity: O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* temp1, ListNode* temp2) {
        ListNode* dummyNode = new ListNode();
        ListNode* ans = dummyNode;
        while(temp1!= NULL && temp2!=NULL){
            if(temp1->val<temp2->val){
                ans->next = temp1;
                temp1 = temp1->next;
            }
            else{
                ans->next = temp2;
                temp2 = temp2->next;
            }
            ans = ans->next;
        }
        ans -> next=temp1?temp1:temp2;
        
        return dummyNode->next;
    }
};
