// Problem Link: https://leetcode.com/problems/4sum/
Approach-1: (3 Pointers + Binary Search)
TIme Complexity: O(N^3LogN), Space Complexity: O(N)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
       set<vector<int>> s;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    long long t = (long long)nums[i]+(long long)nums[j]+(long long)nums[k];
                    int first = k+1, last = n-1;
                    while(first<=last){
                        int mid = (first+last)/2;
                        if(nums[mid]==(target-t)){
                            vector<int> v;
                            v = {nums[i],nums[j],nums[k],nums[mid]};
                            sort(v.begin(),v.end());
                            s.insert(v);
                            break;
                        }else if(nums[mid]>(target-t)){
                            last = mid-1;
                        }else {
                            first = mid+1;
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for (auto it=s.begin(); it!=s.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }
};
