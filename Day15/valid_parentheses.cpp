Problem:: https://www.codingninjas.com/codestudio/problems/795104?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

bool isValidParenthesis(string expression)
{
    int n = expression.size();
    stack<char> st;
    for(int i=0; i<n; i++){
        if(expression[i]=='(' || expression[i]=='[' || expression[i]=='{'){
            st.push(expression[i]);
        }
        else if(!st.empty() && ((st.top()=='(' && expression[i]==')') || (st.top()=='{' && expression[i]=='}') || (st.top()=='[' && expression[i]==']'))) st.pop();
        
        else return false;
    }
    if(st.empty())
    return true;
}

/*
Time Complexity: O(N)
Space Complexity: O(n)
*/
