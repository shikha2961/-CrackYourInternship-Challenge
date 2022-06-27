// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int getMaxIndex(vector<int>& arr, int n ){
        int maxi, maxIndex, i;
        maxi = arr[0];
        maxIndex = 0;
        for(i=1; i<n; i++){
            if(maxi<arr[i]){
                maxi = arr[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
    vector<int> sortArr(vector<int>arr, int n){
        int maxIndex;
        if(n>1){
            maxIndex = getMaxIndex(arr, n);
            swap(arr[n-1], arr[maxIndex]);
            sort(arr,n-1);
        }
    }
};

// { Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>s(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        Solution ob;
        vector<int>v = ob.sortArr(s, n);
        for(auto i : v)
            cout << i << ' ';
        cout << endl;
    }
return 0;
}

  // } Driver Code Ends
