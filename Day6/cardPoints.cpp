Approach-1 (DP and Recursion) Time Limit Exceeded

class Solution {
public:
    int func(vector<int>& cardPoints, vector<vector<vector<int>>> &dp, int k, int l, int r){
        if(k==0) return 0;
        if(dp[l][r][k]!=-1) return dp[l][r][k];
        int pickfirst = cardPoints[l]+func(cardPoints,dp,k-1,l+1,r);
        int pickLast = cardPoints[r] + func(cardPoints,dp,k-1,l,r-1);
        return dp[l][r][k] = max(pickfirst,pickLast);
    }
    
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0;
        int n = cardPoints.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (n+1,vector<int> (k+1,-1)));

        if(k >= cardPoints.size()){
            int sum = 0;
            for(auto it: cardPoints){
                sum += it;
            }
            return sum;
        }
        
        else{
          ans =  func(cardPoints,dp,k,0,n-1);
        }
        return ans;
    }
};

Approach-2: Optimized
class Solution {
public:
   
    int maxScore(vector<int>& cardPoints, int k) {
        int maxScore = INT_MIN;
        int n = cardPoints.size();
        vector<int> rear(k+1), front(k+1);
        for(int i=0; i<k; i++){
            front[i+1] = front[i] + cardPoints[i];
            rear[i+1] = rear[i]+cardPoints[n-i-1];
        }
        for(int i=0;i<=k; i++){
        int currentScore = front[i] + rear[k-i];
        maxScore = max(maxScore, currentScore);
        }
        return maxScore;
    }
};
  
