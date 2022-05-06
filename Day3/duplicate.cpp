Problem Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/

Approach-1 (Using Map)
  class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        for(auto it: mp){
            if(it.second==2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
Time Complexity: O(N)
Space Complexity: O(N)
  
Approach-2 
  Time Complexity: O(N) and Space Complexity: O(1)
    
 class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int cnt = 1;
        for(int i=1; i<n; i++){
           while(i<n && nums[i-1]==nums[i] ){
                cnt++;
                if(i<n) i++;
            }
            if(cnt==2){
                ans.push_back(nums[i-1]);
                cnt = 1;
            }else{
                cnt = 1;
            }
        }
        return ans;
    }
};
