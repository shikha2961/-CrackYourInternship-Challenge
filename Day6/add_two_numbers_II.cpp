Problem: https://leetcode.com/problems/add-two-numbers-ii/

Approach 1: 
/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
class Solution {
public:
     ListNode* reverseList(ListNode* head) {
        ListNode* dummy = NULL;
        while(head!=NULL){
            ListNode* Next = head->next;
            head->next = dummy;
            dummy = head;
            head = Next;
        }
        return dummy;
    }
    
    ListNode* add(ListNode* t1, ListNode* t2) {
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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list1 = reverseList(l1);
        ListNode* list2 = reverseList(l2);
        ListNode* revans = add(list1,list2);
        ListNode* ans = reverseList(revans);
        return ans;
    }
};
