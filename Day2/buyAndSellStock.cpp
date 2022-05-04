Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Approach-1: Brute Force (Result--> Time Limit Exceeded)
Idea is that stock should have minimum price in past but maximum price in fuutre.
  E.g. [7,1,5,3,6,4] --> Maximum profit-> 6(Future stock to sell) - 1(When stock was buy)
 1. Traverse through the array using for loop.
 2. While traversing, always find a maximum number in further elements.
 3. Take the difference maximum element - current element 
 4. Check if it is maximum from previous one, if yes so update it.
   Time Complexity: O(N*N)
   Space Complexity: O(1)
     
 class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            int maxi = *max_element(prices.begin()+i,prices.end());
            int profit = maxi-prices[i];
            ans = max(ans,profit);
        }
        return ans;
    }
};

Approach-2: (Optimized)
Traverse the array, maintain a minimum variable from starting and compare it with every element of the array. 
If that element is greater than the minimum, take the difference and maintain it in maximum, else update the minimum.
  Time Complexity: O(N)
  Space Complexity: O(1)
    
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
