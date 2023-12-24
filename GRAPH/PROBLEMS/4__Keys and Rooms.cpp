PROBLEM :https://leetcode.com/problems/keys-and-rooms/
VIDEO(MIK BHAIYA) :https://www.youtube.com/watch?v=qDHd9n_XGQ8&list=PLpIkg8OmuX-I_49pdy1XFY6OcATnxUrrO&index=5


/*
  TC: same as dfs
  SC: same as dfs

*/

class Solution {
public:
    void dfs(int src,vector<vector<int>>& rooms,vector<bool>&vis){
        vis[src]=true;
        for(auto &v:rooms[src]){
           if(vis[v]==false)
            dfs(v,rooms,vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        dfs(0,rooms,vis);
        for(int i=0;i<n;i++){
            if(vis[i]==false)return false;
        }
        return true;

    }
};
