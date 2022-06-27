// Problem: https://www.codingninjas.com/codestudio/problems/2099908?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

// Approach1: queue using Linked List
class Node{
public:
      int data;
      Node* next;
      Node(int data){
          this->data = data;
          next = NULL;
      }  
};

class Queue {
public:
    Node* head;
    Node* tail;
    int size;
    // Constructor
    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    // Destructor
    ~Queue(){
        Node* temp = head;
        while(temp){
            Node* del = temp;
            temp = temp->next;
            delete del;
        }
    }
    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(size==0) return true;
        return false;
    }

    void enqueue(int data) {
        size++;
        Node* newNode = new Node(data);
        if(head==NULL) {
            head = newNode;
            tail = newNode;
            return ;
        }
        tail->next = newNode;
        tail = newNode;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        int top = head->data;
        Node* tmp = head;
        head = head->next;
        if(head==NULL) tail = NULL;
        delete tmp;
        size--;
        return top;
    }

    int front() {
        if (isEmpty()) {
            return -1;
        }
        return head->data;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(N) // N is the number of queries


// Approach-2 Queue using Arrays
class Queue {
public:
    vector<int> q;
    Queue() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(q.empty()) return true;
        return false;
    }

    void enqueue(int data) {
        q.push_back(data);
    }

    int dequeue() {
        if(q.empty()) return -1;
        int top = q[0];
        q.erase(q.begin());
        return top;
    }

    int front() {
        if(q.empty()) return -1;
        return q[0];
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N) // N is the number of queries
