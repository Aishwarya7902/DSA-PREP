PROBLEM :https://leetcode.com/problems/find-if-path-exists-in-graph/description/
VIDEO (MIK BHAIYA):https://www.youtube.com/watch?v=mbR1XSXidEE&list=PLpIkg8OmuX-I_49pdy1XFY6OcATnxUrrO&index=4


/*
  TC:
  SC:
*/


class Solution {
public:
    void dfs(int source,unordered_map<int,vector<int>>&adj,vector<bool>&vis){
        vis[source]=true;
        for(int &v:adj[source]){
            if(vis[v]==false)
             dfs(v,adj,vis);
        }

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>vis(n,false);
        unordered_map<int,vector<int>>adj;
        for(auto &vec:edges){
           int u=vec[0];
           int v=vec[1];
           adj[u].push_back(v);
           adj[v].push_back(u) ;
        }

        dfs(source,adj,vis);
        return vis[destination];
    }
};
