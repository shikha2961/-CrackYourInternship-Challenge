// Problem:: https://leetcode.com/problems/decode-ways/

// Approach 1:: (Recursion) Result:: Time Limit Exceeded
// Exponential Time Complexity
class Solution {
public:
    int ans = 0;
    void func(string s, int i){
        if(i==s.size()) {
            ans++;
            return;
        }
        if(s[i]=='0') return ;
        func(s,i+1);
        if(i<s.size()-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7')))
        func(s,i+2);
    }
    int numDecodings(string s) {
        if(s[0]=='0'){
            return 0;
        }
        func(s,0);
        return ans;
    }
};

// Approach 2:: Memoization
// Time Complexity:: O(N)
//   Stack Space
//   Extra Space:: O(N)

class Solution {
public:
    int func(string s, int i, vector<int>& dp){
        if(i==s.size()) {
            return 1;
        }
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int l = func(s,i+1,dp);
        int r = 0;
        if(i<s.size()-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7')))
        r = func(s,i+2,dp);
        return dp[i] = l+r;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        if(s[0]=='0'){
            return 0;
        }
        return func(s,0,dp);
    }
};

Approach3 :: Tabulation
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1);
        if(s[0]=='0'){
            return 0;
        }
        dp[n] = 1;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='0') dp[i] = 0;
            else{
                dp[i] = dp[i+1];
                if(i<n-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7')))
                dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};

