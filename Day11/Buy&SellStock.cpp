 // Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Approach-1: Brute Force (TLE)
/* Time Complexity: O(N^2), Space Complexity: O(1) */
  class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
              int  profit = prices[j]-prices[i];
                maxi = max(profit, maxi);
            }
            
        }
        return (maxi<0)? 0: maxi;
    }
};

// Approach2: Optimal 
/* Time Complexity: O(N)
Space Complexity: O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = INT_MAX;
        int maxi = 0;
        for(int i=0; i<n; i++){
            mini = min(prices[i],mini);
            maxi = max((prices[i]-mini), maxi);
        }
        return (maxi<0)? 0: maxi;
    }
};
