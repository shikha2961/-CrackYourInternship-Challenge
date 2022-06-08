Problem: https://leetcode.com/problems/reorder-list/

Approach1: (Using Stack)
/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
class Solution {
public:
    int getlength(ListNode* head){
        int cnt = 0;
        while(head!=NULL){
            head = head->next;
            cnt++;
        }
        return cnt;
    }
    void reorderList(ListNode* head) {
       int n = getlength(head);
       int halfs = n/2;
        stack<int> s;
        ListNode* temp = head;
        while(halfs--){
            temp = temp->next;
        }
        while(temp!=NULL){
            s.push(temp->val);
            temp = temp->next;
        }
        ListNode* pre = head;
        ListNode* nxtnode = head->next;
        while(!s.empty()){
            ListNode* newNode= new ListNode(s.top());
            s.pop();
            
            pre->next = newNode;
            if(!s.empty()){
                 pre->next->next = nxtnode;
                pre = nxtnode;
                nxtnode = nxtnode->next;
            }
        }
        if(n%2!=0) pre->next = NULL;
    }
};

Approach2: without extra space
/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* Node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return Node;
    }
    
    void reorderList(ListNode* head) {
        if(head==NULL or head->next==NULL) return;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        while(temp2 && temp2->next){
            temp1 = temp1->next;
            temp2 = temp2->next->next;
        }
        ListNode* head2 = temp1->next;
        temp1->next=NULL;
        ListNode* newhead2 = reverseList(head2);
        temp1 = head;
        ListNode* nxtnode = temp1->next;
        while(temp1 && newhead2){
            ListNode* newNode = new ListNode(newhead2->val);
            newhead2 = newhead2->next;
            temp1->next = newNode;
            if(newhead2){
                temp1->next->next = nxtnode;
                temp1 = nxtnode;
                nxtnode = nxtnode->next;
            }else if(temp1){
                temp1->next->next = nxtnode;
                temp1 = nxtnode;
                nxtnode = NULL;
            }
            
        }
        
    }
};
