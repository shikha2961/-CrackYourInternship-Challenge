Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

Recursion:
// Time Coomplexity: Exponential
// Space Complexity: O(N) (Auxillary Space)
class Solution {
public:
    int func(vector<int>& prices, int i, int buy, int cap){
        if(cap==0) return 0;
        if(i==prices.size()) return 0;
        int profit = 0;
        if(buy==1){
            int profit1 = -prices[i]+func(prices, i+1, 0, cap);
            int profit2 =  0 + func(prices, i+1, 1, cap);
            profit += max(profit1, profit2);
        }else{
            int profit1 = prices[i]+func(prices, i+1, 1, cap-1);
            int profit2 = func(prices, i+1, 0, cap);
            profit += max(profit1 , profit2);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        
        return func(prices, 0, 1, 2);
    }
};

Memoization:
// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    int func(vector<int>& prices, int i, int buy, int cap, vector<vector<vector<int>>>& dp){
        if(cap==0 || i==prices.size()) return 0;
       
        int profit = 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy==1){
            int profit1 = -prices[i]+func(prices, i+1, 0, cap, dp);
            int profit2 =  0 + func(prices, i+1, 1, cap, dp);
            profit += max(profit1, profit2);
        }else{
            int profit1 = prices[i]+func(prices, i+1, 1, cap-1, dp);
            int profit2 = func(prices, i+1, 0, cap, dp);
            profit += max(profit1 , profit2);
        }
        return dp[i][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return func(prices, 0, 1, 2, dp);
    }
};

Tabulation:
/*
Time Complexity: O(N)
Space Complexity: O(N) // Auxillary space is not there
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                     if(buy==1){
                        dp[i][buy][cap] = max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                    }else{
                        dp[i][buy][cap] = max(prices[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                    }
                }
            }
        }
       return dp[0][1][2];
    }
};

Space Optimization:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(3,0));
        vector<vector<int>> curr(2, vector<int>(3,0));
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                     if(buy==1){
                        curr[buy][cap] = max(-prices[i]+after[0][cap],after[1][cap]);
                    }else{
                        curr[buy][cap] = max(prices[i]+after[1][cap-1],after[0][cap]);
                    }
                }
            }
            after = curr;
        }
       return after[1][2];
    }
};
