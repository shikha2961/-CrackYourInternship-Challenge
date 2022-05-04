class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans = {-1,-1};
        for(int i=0; i<nums.size(); i++){
            if(mp.find(target-nums[i]) != mp.end()){
                ans[1]=i;
                ans[0]=mp[target-nums[i]];
                return ans;
            }
            mp[nums[i]] = i;
        }
        return ans;        
}
};

Time Complexity: O(NlogN)
Space Complexity: O(N)
