PROBLEM :https://leetcode.com/problems/possible-bipartition/description/
VIDEO (MIK BHAIYA) :https://www.youtube.com/watch?v=yYBKsu27f2s&list=PLpIkg8OmuX-I_49pdy1XFY6OcATnxUrrO&index=6

/*
  TC: same as dfs
  SC:same as dfs
*/


class Solution {
public:
    bool dfs(int curr, unordered_map<int,vector<int>>&adj, vector<int>&color,int currColor){
        color[curr]=currColor;
        for(int &v:adj[curr]){
            
            if(color[v]==currColor)return false;
            if(color[v]==-1 && dfs(v,adj,color,1-currColor)==false)return false;

        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>color(n+1,-1);
        unordered_map<int,vector<int>>adj;
        for(auto &vec:dislikes){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            if(color[i]==-1 && dfs(i,adj,color,1)==false)return false;
             
        }
       return true;
    }
};
