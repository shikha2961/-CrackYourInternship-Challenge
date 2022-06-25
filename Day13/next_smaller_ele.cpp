Problem: https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> ans;
    int n = A.size();
    for(int i=n-1; i>0; i--){
        int nse = -1;
        for(int j=i-1; j>=0; j--){
            if(A[j]<A[i]){
                nse = A[j];
                break;
            }
        }
        ans.push_back(nse);
    }
    ans.push_back(-1);
    reverse(ans.begin(), ans.end());
    return ans;
}

TIme complexity: O(N^2)
Space Complexity: O(N)
  
  vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> ans;
    int n = A.size();
    // ans.push(-1);
    stack<int> st;
    st.push(-1);
    for(int i=0; i<n; i++){
        while(!st.empty() && A[i]<=st.top()){
            st.pop();
        }
        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(A[i]);
    }
    return ans;
}
