Problem::  https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

Approach1: (Time Limit Exceeded)
class Solution {
public:
    int ans = 0;
    int N = 1000000000+7;
    void func(vector<int>& nums, int i, int target,vector<int>& chk){
        
        if(i>=nums.size()){
            int maxi = *max_element(chk.begin(), chk.end());
            int mini = *min_element(chk.begin(), chk.end());
            int sum = maxi + mini;
             if(sum<=target && !chk.empty()) ans++;
            return ;
        }
           chk.push_back(nums[i]);
        
        func(nums,i+1,target, chk);
        chk.pop_back();
        func(nums,i+1,target,chk);
    }
    int numSubseq(vector<int>& nums, int target) {
        vector<int> chk;
        func(nums,0,target,chk);
        return ans%N;
    }
};

Approach2: Two Pointer Approach
// TC: O(N)
class Solution {
public:
    int ans = 0;
    int N = 1000000000+7;
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); //TC O(nlogn)
        int n = nums.size();
        vector<int> power(n+1,1); // SC O(n)
        for(int i=1; i<n; i++)   // TC O(n)
            power[i] = (2*power[i-1])%N;
        
        int i=0;
        int j=n-1;
        while(i<=j){  // O(logn)
            if(nums[i]+nums[j]<=target){
                ans = (ans+power[j-i])%N;
                    i++;
            }
            else{
                j--;
            }
        }
        return ans%N;
    }
};
