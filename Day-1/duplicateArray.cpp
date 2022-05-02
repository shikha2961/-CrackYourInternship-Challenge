// Problem Link: https://leetcode.com/problems/find-the-duplicate-number/
/*
Approach-1:
1. Sort the array.
2. Traverse through whole array and check which element is equal to previous one.
  TIme Complexity: O(NLogN) and Space Complexity: O(N) for inbuilt sorting function
*/
 //   Code:
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         sort(nums.begin(),nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]==nums[i])
                return nums[i];
        }
        return -1;
    }
};

/* Approach-2: (By using set or map, they will store only unique.
Time Complexity: O(N)
Space Complexity: O(N)
*/
//  Code:
 class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
            if(it.second==2){
                return it.first;
            }
        }
        return -1;
    }
};

/*
Approach 3: (Optimized) (Linked List Cycle Method)
1. Create 2 pointer fast and slow, initially put them at first element of the array.Fast will move 2 step forward and slow will move 1 step forward.
2. We will move through fast and slow pointers till then pointers do not get at same location.
3. Change the location of first pointer, move it at first element of array.
4. Now move slow and fast pointer will move by 1 step from their respective positions, and the point where they collide that wull be the duplicate number.
Time Complexity: O(N)
Space Complexity: O(1)
*/
// Code:
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         int slow = nums[0], fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        fast = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

