Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/
1. There are lot of ways to buy and sell the stock
2. Try all possible ways
3. Get Best Possible from them

First to write a Recurrence Relation
1. Express everything in terms of index, along with carry a buy variable, if one can buy that stock or not.
  To buy stock, you should sold the previouly bought stock.
  buy will be 1 (If you can buy the stock)
  buy will be 0 (If you can't buy that stock)
2. Explore possibilities on that day.
3. Take the maximum of all the profits you made.
  Time Complexity: O(2^N)    Space Comp.: O(n)               
func(ind,buy){
  if(ind==n) return 0
  if(buy==1) 
    profit1 = -prices[ind]+func(ind+1,0) // If you bought the stock, you can't buy next time until you didn't sell it.
    profit2 = 0 + func(ind+1,1)
    Take max of (profit1 and profit2) add it to in profit
  else  // you have to sell the stock here
    profit1 = prices[ind] + func(ind+1,1)
    profit2 = func(ind+1,0)
    Take max of (profit1 and profit2) add it to in profit
  return profit
}

                 
 Memoization:
       Time Comp.: O(N)     Space Comp.: O(N)+O(N)          
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
  Time Comp.: O(N)        Space Comp: O(N)               
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
