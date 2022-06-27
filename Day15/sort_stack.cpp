Problem: https://practice.geeksforgeeks.org/problems/sort-a-stack/1#

void insert_correct_pos(int x, stack<int>& s){
    if(s.size()==0 || s.top()<x){
        s.push(x);
    }else{
        int a = s.top();
        s.pop();
        insert_correct_pos(x, s);
        s.push(a);
    }
}

void reverse(stack<int>& s){
    if(s.size()>0){
        int x = s.top();
        s.pop();
        reverse(s);
        insert_correct_pos (x, s);
    }
}

void SortedStack :: sort()
{
   reverse(s);
}

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/
