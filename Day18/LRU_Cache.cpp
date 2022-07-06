Problem Link:: https://leetcode.com/problems/lru-cache/

class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int k, int v){
            key = k;
            val = v;
        }
    };
     node* head = new node(-1, -1);
     node* tail = new node(-1, -1);
     int c;
     unordered_map<int, node*> mp;
    LRUCache(int capacity) {
        c = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node* newNode){
        node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deleteNode(node* delNode){
        node* delprev = delNode->prev;
        node* delnext = delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int k) {
        if(mp.find(k)!=mp.end()){
            node* moveNode = mp[k];
            int moveVal = moveNode->val;
            mp.erase(k);
            // Delete node right before the tail
            deleteNode(moveNode);
            // Add the node right after the head
            addNode(moveNode);
            mp[k] = head->next;
            return moveVal;
        }
        return -1;
    }
    
    void put(int k, int value) {
        if(mp.find(k)!=mp.end()){
            node* existNode = mp[k];
            mp.erase(k);
            deleteNode(existNode);
        }
        else if(mp.size()==c){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(k,value));
        mp[k] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
