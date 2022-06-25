Problem Link: https://leetcode.com/problems/next-greater-element-i/submissions/

// Approach1: Brute Force
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i=0; i<n1; i++){
            int nge = -1;
            int j=0;
            while(j<n2){
                if(nums2[j]==nums1[i]){
                    j++;
                    break;
                }
                j++;
            }
            while(j<n2){
                if(nums2[j]>nums1[i]){
                    nge = nums2[j];
                    break;
                }
                j++;
            }
            ans.push_back(nge);
        }
        return ans;
    }
};

// Time Complexity: O(N^2)
// Dynamically auxillary space: O(N)



class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int> st;
        int nge[n2];
        nge[n2-1] = -1;
        st.push(nums2[n2-1]);
        for(int i=n2-2; i>=0; i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty()) nge[i] = -1;
            else nge[i] = st.top();
            st.push(nums2[i]);
        }
        unordered_map<int,int> mp;
        for(int i=0; i<n2; i++) mp[nums2[i]] = i;
        for(int i=0; i<n1; i++){
            int ind = mp[nums1[i]];
            ans.push_back(nge[ind]);
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)
