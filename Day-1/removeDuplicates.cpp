Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Approach-1 (Using Extra space, we can easily do the que but it will not satisfy the condition of que.
            TIme Complexity: O(N)
            Space Complexity: O(N)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int i  = 0;
        for(auto it: mp){
            nums[i] = it.first;
            i++;
        }
        return i;
    }
};
            
Approach-2 (2 Pointer approach) Without using extra space
          Time Complexity: O(N)
          Space Complexity: O(1)
            
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        for(int right = 1; right<n; right++){
            if(nums[left]!=nums[right])
                left++;
            nums[left] = nums[right];
        }
        return left + 1;
    }
};
