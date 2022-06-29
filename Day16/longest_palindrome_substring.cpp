Problem::

//************************************* Brute Force Solution ***************************************************************//
/*
Result :::: Time Limit Exceeded
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxi = 0;
    string ans = "";
  // Function to get the maximum palindrome substring
    string longestPalindrome(string);
  // Function to generate all substrings
    void get_all_substrings(string, int);
  // Function to check the given string is palindrome or not
    void check_palindrome(string s);
};

void Solution ::check_palindrome(string s)
{
    int n = s.size();
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return;
        }
        i++;
        j--;
    }
    int f = maxi;
    maxi = max(maxi, n);
    if (f != maxi)
    {
        ans = s;
    }
}

void Solution::get_all_substrings(string s, int ind)
{
    if (ind == s.size())
        return;
    string str = "";
    for (int i = ind; i < s.size(); i++)
    {
        str += s[i];
        check_palindrome(str);
    }
    return get_all_substrings(s, ind + 1);
}

string Solution::longestPalindrome(string s)
{
    get_all_substrings(s, 0);
    return ans;
}

int main()
{
    string str;
    getline(cin, str);
    Solution obj;
    string ans = obj.longestPalindrome(str);
    cout << ans << endl;
    return 0;
}


//****************************************************** USing Dynamic Programming *************************************************************//
// Time Complexity:: O(N^2)
// Space Complexity:: O(N^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        int maxLength = 1;
        
        for(int i=0; i<n; i++){
            dp[i][i] = true;
        }
        
        int start = 0;
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = true;
                start = i;
                maxLength = 2;
            }
        }
        
        for(int k=3; k<=n; k++){
            for(int i=0; i<n-k+1; i++){
                int j = i+k-1;
              if(dp[i+1][j-1] && s[i]==s[j]){
                  dp[i][j] = true;
                  if(k>maxLength){
                    start = i;
                    maxLength = k;
                }
              }
            }
        }
        
        string ans = "";
        for(int i=start; i<=(start+maxLength-1); i++){
            ans += s[i];
        }
        return ans;
        
    }
};



