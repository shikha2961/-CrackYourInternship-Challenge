Problem: https://leetcode.com/problems/implement-queue-using-stacks/


class MyQueue {
public:
   
    stack<int> s1,s2;
    
    void push(int x) {
       s1.push(x);
     }
  // Time complexity : O(1)  
  
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
  // Time complexity: Amortized O(1), Worst-case O(n).  
  
  
    int peek() {
         if(!s2.empty())    return  s2.top();
         else{
           while(!s1.empty()){
            int d = s1.top();
            s1.pop();
            s2.push(d);
            }
          return s2.top();
         }
        return -1;
    }
    
    bool empty() {
        if(s2.empty()) return true;
        return false;
    }
  // Time complexity : O(1).
  // Space complexity : O(1).
};
