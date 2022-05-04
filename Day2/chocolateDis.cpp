Problem Link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1/#

An efficient solution is based on the observation that to minimize the difference, we must choose consecutive elements from a sorted packet. 
  We first sort the array arr[0..n-1], then find the subarray of size m with the minimum difference between the last and first elements.
  
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    long long mini = INT_MAX;
     sort(a.begin(), a.end());
     int i=0, j=m-1;
     while(j<n){
         mini = min(a[j]-a[i], mini);
         i++;
         j++;
     }
     return mini;
    }   
};

Time Complexity: O(NlogN)
Space Complexity: O(N)
