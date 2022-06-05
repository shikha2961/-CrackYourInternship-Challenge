// Problem Link: https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1#
/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
Appraoach: (By counting 0s, 1s, and 2s)
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        
        while(head!=NULL){
            if(head->data==1) cnt1++;
            else if(head->data==2) cnt2++;
            else cnt0++;
            head = head->next;
        }
        Node* ans=new Node(0);
        Node* dummy = ans;
        while(cnt0--){
            Node* newNode = new Node(0);
            dummy -> next = newNode;
            dummy = dummy->next;
        }
        while(cnt1--){
            Node* newNode = new Node(1);
            dummy -> next = newNode;
            dummy = dummy->next;
        }
        while(cnt2--){
            Node* newNode = new Node(2);
            dummy -> next = newNode;
            dummy = dummy->next;
        }
        return ans->next;
    }
};


Approach2 : (By changing the links)
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node* cnt0 = new Node(0);
        Node* cnt1 = new Node(0); 
        Node* cnt2 = new Node(0);
        Node* d0 = cnt0; 
        Node* d1 = cnt1;
        Node* d2 = cnt2;
        while(head!=NULL){
            if(head->data==0){
                d0->next = head;
                d0 = d0->next;
            } else if(head->data==1){
                d1->next = head;
                d1 = d1->next;
            }else{
                d2->next = head;
                d2 = d2->next;
            }
            head=head->next;
        }
        d0->next =  (cnt1->next)? cnt1->next : cnt2->next;
        d1->next = cnt2->next;
        d2->next = NULL;
        return cnt0->next;
    }
};
