Problem: https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0) return ans;
        sort(intervals.begin(),intervals.end());
        vector<int> tempInterval;
        tempInterval = intervals[0];
        for(auto it: intervals){
           if(tempInterval[1]>=it[0]){
               tempInterval[1] = max(it[1],tempInterval[1]);
           }else{
               ans.push_back(tempInterval);
               tempInterval = it;
           }
         }
        ans.push_back(tempInterval);
    return ans;
    }
};
