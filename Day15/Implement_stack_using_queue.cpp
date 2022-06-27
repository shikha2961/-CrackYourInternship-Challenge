Problem: https://leetcode.com/problems/implement-stack-using-queues/

// Using 2 queues
class MyStack {
public:
    queue<int> q1,q2; 
    
    void push(int x) {
        q2.push(x);
       while(!q1.empty()){
            int d = q1.front();
            q1.pop();
            q2.push(d);
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
    
    int pop() {
        if(q1.empty()) return -1;
        int d = q1.front();
            q1.pop();
        return d;
    }
    
    int top() {
        if(q1.empty()) return -1;
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty()) return true;
        return false;
    }
};

// Push : O(N)
// Pop : O(1)
// Space Complexity: O(N)


// Using Single Queue
class MyStack {
public:
    queue<int> q1;
    
    void push(int x) {
        q1.push(x);
        int size = q1.size();
        while(size>1){
           int temp = q1.front();
           q1.pop();
           q1.push(temp);
           size--;
        }
    }
    
    int pop() {
        if(q1.empty()) return -1;
        int temp = q1.front();
        q1.pop();
        return temp;
    }
    
    int top() {
        if(q1.empty()) return -1;
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty()) return true;
        return false;
    }
};

// Push : O(N)
// Pop : O(1)
// Space Complexity: O(N)
