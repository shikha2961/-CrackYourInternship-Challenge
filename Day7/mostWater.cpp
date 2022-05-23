Problem Link: https://leetcode.com/problems/container-with-most-water/

Approach-1: (Brute Force)
Take every possiblity to calculate the area and compare it with current maximum and update it.
  class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;
        int n = height.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans = max(min(height[i],height[j])*(j-i) , ans);
            }
        }
        return ans;
    }
};
Time Complexity: O(N^2) and Space Complexity: O(1)
  
Approach-2: (Optimized)
1. Take 1st pointer i at initial position and pointer j at last position. 
2. Calculate area between these 2 pointers.
3. Move less height's pointer (if i in forward direction and j in backward direction), because we will not get the better result by using this pointer.
  
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN;
        int n = height.size();
        int i = 0, j = n-1;
        while(i<=j){
            ans = max(ans, min(height[i],height[j])*(j-i));
            if(height[i]<height[j])  i++;
            else  j--;
        }
        return ans;
    }
};
Time complexity: O(N) Space complexity: O(1)
