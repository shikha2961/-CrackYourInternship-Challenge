// Problem: https://leetcode.com/problems/combination-sum/

/*
Approach (Recursion):
* We have to create the combinations from a given array whose sum is equal to target (any element from array can be chosen any number of times)
* E.g. [2,3,6,7]   Result: [[2,2,3],[7]]
* Basic Idea is we will pick the element from array or not pick the element.
        func(ind, target, ds[])
If I pick it, so there is no need to increase the index, because we can take time element any number of times, we picked the curr element into ds, 
so we need to reduce it from target:   func(ind, target-arr[ind], ds[arr[ind]])
If I don't pick it, func(ind+1, target, ds)
  
  Base Case: When (ind == arr.size()) so, we will check if the target==0, if it is 0, then store the ds values to return in the answer
 
While coming back in recursion, we need to remove the elements from ds as well to propagate the further process of recursion.
*/

    class Solution {
public:
    vector<vector<int>> ans;
    int Sum = 0;
    void func(vector<int>& candidates, int target, int i, vector<int>& ds){
        // Base Case
        if(i==candidates.size()){
            
            if(target==0)
            ans.push_back(ds);
            return;
        }
        
        // Pick the element from candidates
        if((target-candidates[i])>=0){
            ds.push_back(candidates[i]);
            func(candidates, target-candidates[i], i, ds);
            ds.pop_back();
        }
        
        // Don't pick the element from candidates
        func(candidates, target, i+1, ds);
        
    }
      
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // ds to store the combinations
       vector<int> ds;
        
       func(candidates, target, 0, ds);
        return ans;
    }
};
