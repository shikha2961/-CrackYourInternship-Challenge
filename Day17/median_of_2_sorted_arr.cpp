Problem:: https://leetcode.com/problems/median-of-two-sorted-arrays/

// Time Complexity:: O(max(m,n))
// Space Complexity:: O(m+n)
class Solution {
public:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        int i=0,j=0,k=0;
        int m = nums1.size(), n = nums2.size();
        vector<int> merged_array;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                merged_array.push_back(nums1[i++]);
            }else{
                merged_array.push_back(nums2[j++]);
            }
        }
        while(i<m){
            merged_array.push_back(nums1[i++]);
        }
        while(j<n){
            merged_array.push_back(nums2[j++]);
        }
        return merged_array;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged_array = merge(nums1, nums2);
        int n = merged_array.size();
        if(n%2!=0){
            return merged_array[n/2];
        }
        return ((double)merged_array[n/2]+(double)merged_array[(n/2)-1])/2;
    }
};

Time Complexity:: O(log(m+n))
Space Complexity:: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size() , n = nums2.size();
        int low = 0, high = m;
        while(low<=high){
            int cut1 = (low+high)>>1;
            int cut2 = (m+n+1)/2 - cut1;
            
            int left1 = cut1==0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2==0 ? INT_MIN : nums2[cut2-1];
            
            int right1 = cut1==m ? INT_MAX : nums1[cut1];
            int right2 = cut2==n ? INT_MAX : nums2[cut2];
            
            if(left1<=right2 && left2<=right1){
                if((m+n) % 2 == 0)
                    return (max(left1, left2)+min(right1, right2))/2.0;
                else
                    return max(left1, left2);
            }
            
            else if(left1>right2){
                high = cut1-1;
            }
            
            else{
                low = cut1+1;
            }
            
        }
        return 0.0;
    }
};
