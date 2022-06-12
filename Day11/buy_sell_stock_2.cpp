Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

Approach 1: (Using recursion) TLE
class Solution {
public:
    int func(int i, vector<int>& prices, int buy){
       if(i>=prices.size()) return 0;
        int profit = 0;
        if(buy==1){
            int profit1 = -prices[i]+func(i+1,prices,0);
            int profit2 = 0+func(i+1,prices,1);
            profit += max(profit1,profit2);
        }else{
            int profit1 = prices[i]+func(i+1,prices,1);
            int profit2 = 0+func(i+1,prices,0);
            profit += max(profit1,profit2);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return func(0,prices,1);
    }
};

Memoization
class Solution {
public:
    int func(int i, vector<int>& prices, int buy, vector<vector<int>>& dp){
       if(i>=prices.size()) return 0;
        int profit = 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==1){
            int profit1 = -prices[i]+func(i+1,prices,0,dp);
            int profit2 = 0+func(i+1,prices,1,dp);
            profit += max(profit1,profit2);
        }else{
            int profit1 = prices[i]+func(i+1,prices,1,dp);
            int profit2 = 0+func(i+1,prices,0,dp);
            profit += max(profit1,profit2);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return func(0,prices,1,dp);
    }
};

Tabulation:
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
         int profit = 0;
        dp[n][0] = dp[n][1] = 0;
        for(int i=n-1; i>=0; i--){
           
            for(int buy = 0; buy<=1 ; buy++){
                 if(buy==1){
                    int profit1 = -prices[i]+dp[i+1][0];
                    int profit2 = 0+dp[i+1][1];
                    profit = max(profit1,profit2);
                 }else{
                    int profit1 = prices[i]+dp[i+1][1];
                    int profit2 = 0+dp[i+1][0];
                    profit = max(profit1,profit2);
                 }
               dp[i][buy] = profit;
            }
        }
       return dp[0][1];
    }
};
