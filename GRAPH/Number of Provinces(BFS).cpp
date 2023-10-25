PROBLEM:https://leetcode.com/problems/number-of-provinces/description/
VIDEO:https://www.youtube.com/watch?v=YDMkSvNdB20&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=11

/*
  TC:
  SC:
*/


class Solution {
public:
    int n;
    void bfs(int u,unordered_map<int,vector<int>>&mp,vector<bool>&vis){
        
        queue<int>q;
        q.push(u);
        vis[u]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int &v:mp[curr]){
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         n=isConnected.size();
        
        //making of map
        unordered_map<int,vector<int>>mp;
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                if(isConnected[u][v]==1)
                {
                    mp[u].push_back(v);
                    mp[v].push_back(u);
                }
            }
        }
        
        int cnt=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,mp,vis);
                cnt++;
            }
        }
        return cnt;
    }
};
