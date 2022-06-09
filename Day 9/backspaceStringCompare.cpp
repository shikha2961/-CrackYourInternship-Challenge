Problem: https://leetcode.com/problems/backspace-string-compare/

// Appraoch1: (Without Extra Space of stack)
/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
         int i = s.size()-1;
        int j = t.size()-1;
        int sskip = 0, tskip=0;
        while(i>=0 || j>=0){
            while(i>=0){
                if(s[i]=='#'){ sskip++;  i--; }
                else if(sskip>0){ sskip--; i--; }
                else break;
            }
            while(j>=0){
                 if(t[j]=='#'){ tskip++; j--; }
                 else if(tskip>0){  tskip--;  j--; }
                 else break;
           }
           if(i>=0 && j>=0 && s[i]!=t[j]) return false;
           if ((i >= 0) != (j >= 0)) return false;
             i--; j--;
        }
        return true;
    }
};

 // Approach2: (Using Stack)
/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
class Solution {
public:
   bool stackaresame(stack<char> s1, stack<char> t1){
        if(s1.size()!=t1.size()) return false;
        while(!s1.empty() && !t1.empty()){
            if(s1.top()!=t1.top()){
                return false;
            }
            s1.pop();
            t1.pop();
        }
        return true;
   }
    stack<char> pushInstack(string s){
        stack<char> s1;
         for (auto it: s){
            if(it != '#' ){
                s1.push(it);
            }else if(it=='#' && !s1.empty()){
                s1.pop();
            }
        }
        return s1;
    }
    bool backspaceCompare(string s, string t) {
        stack<char> s1 = pushInstack(s);
        stack<char> t1 = pushInstack(t);
        bool ans = stackaresame(s1,t1);
        return ans;
    }
};
