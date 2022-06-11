// Problem: https://leetcode.com/problems/majority-element/

/*
Approach 1 : (Using Hashmap)
TC: O(N)
SC: O(N)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        int maxi = INT_MIN;
        int ans = 0;
        for(auto it: mp){
            int num = maxi;
            maxi = max(maxi,it.second);
            if(maxi!=num){
                ans = it.first;
            }
        }
        return ans;
    }
};

/*
Approach 2 : (Sorting)
TC: O(Nlogn)
SC: O(N) for sorting
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

/*
Approach 3: (Moore Voting Algorithm)
TC: O(N)
SC: O(1)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0, ele=0;
        for(auto it: nums){
            if(cnt==0){
                ele=it;
            }
            if(ele==it){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return ele;
    }
};
