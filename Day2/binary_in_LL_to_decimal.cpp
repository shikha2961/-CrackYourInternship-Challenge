// Problem: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

/*
// Same in all 3 approaches
Time Complexity: O(N)
Space Complexity: O(1)
*/ 

// Approach-1 (Using Positional Notation)
class Solution {
public:
    int get_length(ListNode* head){
        int len = 0;
        while(head!=NULL){
            len++;
            head = head->next;
        }
        return len;
    }
    int getDecimalValue(ListNode* head) {
       int len = get_length(head);
        int ans = 0;
        while(head!=NULL ){
            len--;
           ans += pow(2,len)*head->val;
            head = head->next;
        }
        return ans;
    }
};

// Approach-2 (Using Doubling)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
       int num = head->val;
        while(head->next!=NULL ){
           num = num*2+head->next->val;
            head=head->next;
        }
        return num;
    }
};

// Approach-3 (Bit Manipulation)
 class Solution {
public:
    int getDecimalValue(ListNode* head) {
       int num = head->val;
        while(head->next!=NULL ){
           num = (num<<1) | head->next->val;
            head=head->next;
        }
        return num;
    }
};

  
