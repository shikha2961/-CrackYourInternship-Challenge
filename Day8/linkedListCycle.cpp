// Problem: https://leetcode.com/problems/linked-list-cycle/

// Approach 1: Using Hashmap
/*
Time Complexity: O(N)
Space Complexity: O(N)
  */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       unordered_map<ListNode*, int> mp;
        while(head!=NULL){
            if(mp.find(head)==mp.end()){
                mp[head]++;
            }else {
                return true;
            }
            head=head->next;
        }
        return false;
    }
};


// Approach-2: (Using Fast and Slow Pointer)
/*
Time Complexity: O(N)
Space Complexity: O(1)
  */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};
