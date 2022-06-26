Problem: https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool dfs(int node, vector<int>& color, int c, vector<vector<int>>& graph){
        color[node] = c;
        for(auto it: graph[node])
            if((color[it]==color[node]) || (color[it]==-1 && !dfs(it,color, 1-color[node], graph)))
                return false;
           
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0; i<n; i++){
               if(color[i]==-1 && !dfs(i,color, 1, graph)) return false;
        }
        return true;
    }
};
