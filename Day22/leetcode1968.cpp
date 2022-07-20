// Problem:: https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

/*
Approach1: (Sorting)
We want to make sure that, nums[i-1]<nums[i]>nums[i+1]
  First Sort the array,
  Now Put the starting half elements on even indexes in resulted array and rest elements on left space.
  E.g. [6,2,0,9,7]
  1. [0,2,6,7,9]
  2. result = [_ _ _ _ _] --> [0 _ 2 _ 6 ]
  3. [0 7 2 9 6]
  */
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans(n);
        int i=0; 
        int j=0;
        while(i<n && j<n){
            ans[j] = nums[i];
            i++;
            j += 2;
        }
        j=1;
        while(i<n && j<n){
            ans[j] = nums[i];
            i++;
            j += 2;
        }
        return ans;
    }
};


//Approach2:
/*
* Scan from left to right & swap for Invalid terms
* Scan from right to left & swap for Invalid terms
*/
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=1; i<n-1; i++){
            if(2*nums[i]==(nums[i-1]+nums[i+1])){
                swap(nums[i], nums[i+1]);
            }
        }
        for(int i=n-2; i>0; i--){
            if(2*nums[i]==(nums[i-1]+nums[i+1])){
                swap(nums[i], nums[i-1]);
            }
        }
        return nums;
    }
};
