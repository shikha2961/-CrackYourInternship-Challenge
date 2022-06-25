Problem: https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node* , Node*> mp;
    Node* cloneGraph(Node* node) {
       if(node==NULL) return NULL;
        if(mp.find(node)==mp.end()){
            mp[node] = new Node(node -> val, {});
            for (auto it: node->neighbors){
                mp[node]->neighbors.push_back(cloneGraph(it));
            }
        }
        return mp[node];
    }
};
// TIme Complexity: O(E.V)

// Using BFS
class Solution {
public:
    unordered_map<Node* , Node*> mp;
    Node* cloneGraph(Node* node) {
       if(node==NULL) return NULL;
        
        Node* first = new Node(node -> val, {});
        mp[node] = first;
        
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
             Node* curr = q.front();
            q.pop();
            for(auto it: curr->neighbors){
                if(mp.find(it)==mp.end()){
                mp[it] = new Node(it -> val, {});
                q.push(it);
                } 
                mp[curr] -> neighbors.push_back(mp[it]);
            }
            
        }
       
        return mp[node];
    }
};
