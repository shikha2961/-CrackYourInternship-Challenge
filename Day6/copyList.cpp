Problem:
Approach: (Brute Force)
/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
       map<Node*, Node*> mp;
       Node* curr = head;
        while(curr){
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }
        for (auto it: mp){
            Node* key  = it.first;
            mp[key]->next = mp[key->next];
            mp[key]->random = mp[key->random];
        }
        return mp[head];
    }
};

Approach (Optimal Approach)
  /*
  Time Complexity: O(N)
  Space Complexity: O(1)
  */
  
 class Solution {
public:
    Node* copyRandomList(Node* head) {
       Node* iter = head;
        Node* front = head;
        while(iter!=NULL){
            front = iter->next;
            Node* copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }
      
        iter = head;
        while(iter!=NULL){
            if(iter->random!=NULL){
                iter->next->random = iter->random->next;
                
            }
            iter = iter->next->next;
        }
      
        iter = head;
        Node* ans = new Node(0);
        Node* copy = ans;
        while(iter!=NULL){
            Node* front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy->next;
            iter = iter->next;
        }
        return ans->next;
    }
};
