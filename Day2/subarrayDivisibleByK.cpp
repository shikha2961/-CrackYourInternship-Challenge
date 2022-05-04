Problem Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/

Approach-1: Brute Force

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(sum%k==0) cnt++;
            }
        }
        return cnt;
    }
};

Time Complexity: O(N*N)
Space Complexity: O(1)
  
  
 Approach-2: Optimized
 Index: 0 1 2 3 4 5
 Ele:   4 5 0 -2 -3 1
 sum%k  4 4 4 2 4 0   
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(sum%k==0) cnt++;
            }
        }
        return cnt;
    }
};
