PROBLEM:https://practice.geeksforgeeks.org/problems/number-of-provinces/1
VIDEO:https://www.youtube.com/watch?v=70LNE8RMPNc&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=10

/*
  by making graph 
*/
class Solution {
  public:
    int n;
    void dfs(int u,unordered_map<int,vector<int>>&mp,vector<bool>&vis){
        vis[u]=true;
        for(int &v:mp[u]){
            if(!vis[v])
             dfs(v,mp,vis);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        n=adj.size();
        unordered_map<int,vector<int>>mp;
        
        //making of graph
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]==1){
                    mp[i].push_back(j);
                }
            }
        }
        int cnt=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,mp,vis);
                cnt++;
            }
        }
        return cnt;
        
    }
};
