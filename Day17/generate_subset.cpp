Problem:: https://leetcode.com/problems/subsets/

// Approach 1: Using Recursion
class Solution {
public:
    vector<vector<int>> ans;
    void func(vector<int>& nums, int ind, vector<int>& arr){
        if(ind==nums.size()) {
            ans.push_back(arr);
            return;
        }
        // indth element is not in arr
            func(nums, ind+1, arr);
        
        // indth element consider in arr
            arr.push_back(nums[ind]);
            func(nums, ind+1, arr);
            arr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        func(nums, 0, subset);
        return ans;
    }
};

// Approach 2:: Using Bit Masking

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subset_cnt  = (1<<n);
        for(int mask = 0; mask<subset_cnt; mask++){
            vector<int> subset;
            for(int i=0; i<n; i++){
                if((mask & (1<<i)) != 0){
                    subset.push_back(nums[i]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};
