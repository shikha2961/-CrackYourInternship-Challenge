// Problem: https://leetcode.com/problems/majority-element-ii/

// Approach 1: (Using hashmaps)
/*
TC: O(N), SC: O(N)
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        for(auto it: mp){
            if(it.second>n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

// Approach 2: (Extended Boyer Moore’s Voting Algorithm)
/* 
TC: O(N) , SC: O(1)
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0, num1 = -1, num2 = -1;
        for(auto it: nums){
            if(it==num1) cnt1++;
            else if(it==num2) cnt2++;
            else if(cnt1==0){
                num1 = it;
                cnt1 = 1;
            }else if(cnt2==0){
                num2 = it;
                cnt2 = 1;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(auto it: nums){
            if(it==num1) cnt1++;
            else if(it==num2) cnt2++;
        }
        if(cnt1>n/3){
            ans.push_back(num1);
        }
        if(cnt2>n/3){
            ans.push_back(num2);
        }
        return ans;
    }
};
