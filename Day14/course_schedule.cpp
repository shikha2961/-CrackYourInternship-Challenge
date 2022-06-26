// Problem: https://leetcode.com/problems/course-schedule/

// Using DFS
class Solution {
public:
    bool detectCycle(int node, vector<vector<int>>& prerequisites, vector<int> &vis){
        if(vis[node]==2) return true;
        
        vis[node] = 2;
        for(auto it: prerequisites[node]){
            if(vis[it]!=1){
               if(detectCycle(it,prerequisites, vis)){
                   return true;
               } 
            }
        }
      
        vis[node] = 1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        if(n==1 || numCourses==1) return true;
        vector<int> vis(numCourses+1, 0);
        vector<vector<int>> adj(numCourses);
      
        for(int i=0; i<n; i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
       
        for(int i=0; i<numCourses; i++){
            if(vis[i]==0){
               if(detectCycle(i,adj, vis)){
                   return false;
               } 
            }
        }
        return true;
    }
};

// Using BFS (Toplogical Sort) Khan's Algorithm
class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        if(n==1 || numCourses==1) return true;
        vector<int> vis(numCourses+1, 0);
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<n; i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0; i<adj.size(); i++){
            for(auto it: adj[i]){
                vis[it]++;
            }
        }
        queue<int> q;
        int cnt = 0;
        for(int i=0; i<adj.size(); i++){
            if(vis[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node]){
                vis[it]--;
                if(vis[it]==0) q.push(it);
            }
        }
        if(cnt==numCourses) return true;
        return false;
    }
};
