Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

// Approach: (Using Map)
1. Store all the values of list into map.
2. Now we have unique values.
3. Assign these values into list and return it.
  /*
  Time Complexity: O(N)
  Space Complexity: O(N)
  */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> mp;
        while(head!=NULL){
            mp[head->val]++;
            head = head->next;
        }
        ListNode* ans = new ListNode();
        ListNode* dummy = ans;
        for(auto it: mp){
            ListNode* newNode = new ListNode(it.first);
            dummy->next = newNode;
            dummy = dummy->next;
        }
        return ans->next;
    }
};


Approach 2:
/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
       ListNode* prev = head;
       ListNode* curr = head->next;
        while(curr!=NULL){
            while(curr!=NULL && prev->val==curr->val ){
                curr = curr->next;
            }
            if(curr==NULL){
                prev->next = NULL;
            }
            if(prev!=NULL && curr!=NULL && prev->val!=curr->val){
                prev->next = curr;
                prev=prev->next;
                curr=curr->next;
            }
        }
        return head;
    }
};
