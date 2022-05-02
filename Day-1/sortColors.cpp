// Approach-1 (Using Sorting Algorithms)
//   We can use any sorting algo. Time and Space Complexity depends upon the which sorting algo, we are using.
  
//  Approach-2: 
//  1. First traverse the array, count the 0s, 1s and 2s.
//  2. In 2nd traverse, update the array elements first with 0s, then 1s and then 2s.
//  Time Complexity: O(N)+O(N)
//  Space Complexity: O(1)
   
// Code:
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==0) cnt0++;
            else if(nums[i]==1) cnt1++;
            else cnt2++;
        }
        int j = 0;
        while(cnt0>0 && j<n){
            nums[j] = 0;
            j++;
            cnt0--;
        }
        while(cnt1>0 && j<n){
            nums[j] = 1;
                j++;
            cnt1--;
        }
        while(cnt2>0 && j<n){
            nums[j] = 2;
            j++;
            cnt2--;
        }
    }
};

// Approach-3 (3 Pointer approach) (Variation of Dutch National Flag Algorithm)
// 1. Take 3 ptrs low, mid, high
// 2. Move 0s to the left, 2s to the right, 1s will be in the middle range of the array
// 3. low = 0, mid = 0, high = n-1
// 4. arr[mid]==0 --> swap(arr[mid],arr[low]) low++ mid++
//    arr[mid]==1 --> mid++
//    arr[mid]==2 --> swap(arr[mid],arr[high] high--
// Time Complexity: O(N)
// Space Complexity: O(1)                        
//  Code: 
     class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid = 0;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};                  
  
