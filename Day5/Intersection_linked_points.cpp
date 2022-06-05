Problem: https://leetcode.com/problems/intersection-of-two-linked-lists/

// M -> size of linked list of headA
// N -> size of linked list of headB
Approach1: (Brute Force)
/*
Time Complexity: O(M*N)
Space Complexity: O(1)
*/
class Solution {
public:
   ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        while(tempA!=NULL){
            ListNode* tempB = headB;
            while(tempB!=NULL){
                if(tempA==tempB){
                    return tempA;
                }
                tempB = tempB->next;
            }
            tempA = tempA->next;
        }
        return NULL;
    }
};

Approach-2: (Using Hasmap)
/*
Time Complexity: O(M+N)
Space Complexity: O(M)
*/
class Solution {
public:
   ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mp;
        while(headA!=NULL){
            mp[headA]++;
            headA =headA->next;
        }
       while(headB!=NULL){
           if(mp.find(headB)==mp.end()){
               mp[headB]++;
           }else{
               return headB;
           }
           headB = headB->next;
           
       }
       return NULL;
    }
};

// Approach 3: (Optimal)
/*
Time complexity: O(2*N)
Space Complexity: O(1)
*/
class Solution {
public:
   ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* dummy1 = headA;
        ListNode* dummy2 = headB;
       while(true){
           if(dummy1==dummy2) return dummy1;
           if(dummy1==NULL && dummy2==NULL) return NULL;
           
           dummy1 = dummy1==NULL ? headB : dummy1->next;
           
           dummy2 = dummy2==NULL ? headA : dummy2->next;
       }
       
       return NULL;
    }
};
