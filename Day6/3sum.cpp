class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
           int p=i+1,q=n-1;
            while(p<q){
                int sum = nums[i]+nums[p]+nums[q];
                vector<int> temp;
                if(sum<0)      p++;
                else if(sum>0) q--;
                else{
                   vector<int> temp = {nums[i],nums[p],nums[q]};
                    v.push_back(temp);
                    while(p+1<q && nums[p]==nums[p+1]) p++;
                    while(q-1>p && nums[q]==nums[q-1]) q--;
                    p++;
                    q--;
                }
            }
            
        }
        return v;
    }
};
