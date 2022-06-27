Problem: https://leetcode.com/problems/implement-queue-using-stacks/solution/

class MyQueue {
public:
   
    stack<int> s1,s2;
    int front = -1;
    
    // TC: O(1), SC: O(N)
    void push(int x) {
       if(s1.empty()) front = x;
        s1.push(x);
    }
    
    // TC: Amortized: O(1), Worst Case: O(N)
    // SC: O(1)
    int pop() {
        if(!s2.empty()){
            int d = s2.top();
            s2.pop();
            return d;
        }
       else{
           while(!s1.empty()){
            int d = s1.top();
            s1.pop();
            s2.push(d);
        }
          int d = s2.top();
            s2.pop();
            return d;
       }
        return -1;
    }
    
    // TC: O(1), SC: O(1)
    int peek() {
         if(!s2.empty())    return  s2.top();
         return front;
    }
    
    // TC: O(1), SC: O(1)
    bool empty() {
        if(s2.empty()) return true;
        return false;
    }
};
