PROBLEM:https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
VIDEO:(https://www.youtube.com/watch?v=ZsGTpXm966E&list=PLpIkg8OmuX-I_49pdy1XFY6OcATnxUrrO&index=3)

  /*
  tc:same as dfs
  sc:
*/

  class Solution {
public:
    void dfs(int indx,vector<vector<int>>& stones,vector<bool>&vis){
        vis[indx]=true;
        for(int i=0;i<stones.size();i++){
            int r=stones[indx][0];
            int c=stones[indx][1];
            if(vis[i]==false && (stones[i][0]==r || stones[i][1]==c))dfs(i,stones,vis);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool>vis(n,false);
        int grp=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i])continue;
            dfs(i,stones,vis);
            grp++;
        }
        return n-grp;
    }
};
