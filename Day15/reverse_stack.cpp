Problem:: https://practice.geeksforgeeks.org/problems/reverse-a-stack/1/#

class Solution{
public:
    vector<int> ans;
    vector<int> Reverse(stack<int> st){
        if(st.empty()) return ans;
        ans.push_back(st.top());
        st.pop();
        return Reverse(st);
    }
};
