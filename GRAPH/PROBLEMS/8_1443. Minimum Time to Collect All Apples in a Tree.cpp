PROBLEM :https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/

VIDEO(MIK BHAIYA) :https://www.youtube.com/watch?v=qSBvKlUq0xo&list=PLpIkg8OmuX-I_49pdy1XFY6OcATnxUrrO&index=9
Problem Name : Minimum Time to Collect All Apples in a Tree
Company Tags  : Microsoft
/*
  TC:O(V+E) ....same as dfs
  SC:  .......saame as dfs
*/



class Solution {
public:
    int DFS(unordered_map<int,vector<int>>&adj,int curr,int parent,vector<bool>& hasApple){
        int time=0;
        for(int &child:adj[curr]){
            if(child==parent)continue;

            int time_from_child=DFS(adj,child,curr,hasApple);
            if(time_from_child>0 || hasApple[child]){
                time+= time_from_child+2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        //making of graph

        unordered_map<int,vector<int>>adj;

        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return DFS(adj,0,-1,hasApple);
    }
};
