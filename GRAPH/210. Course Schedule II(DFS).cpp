PROBLEM:https://leetcode.com/problems/course-schedule-ii/description/
VIDEO:https://www.youtube.com/watch?v=yiR95dxinjs&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=16

/*
  IMP NOTE 🔥🔥
->  If u do this question via DFS then first check if has cycle or not ........if it has cycle then return empty vector
 ->u can give topo sort of using dfs only when u r 100 % sure if  the graph does not have a cycle ....if graph has a cycle then it will give wrong ans🙅‍♂️🙅‍♂️
*/

  class Solution {
public:
    bool dfsHelp(int u,unordered_map<int,vector<int>>&adj,vector<bool>&vis,vector<bool>&inRecursion){
        vis[u]=true;
        inRecursion[u]=true;
        for(int &v:adj[u]){
            if(!vis[v]){
                if(dfsHelp(v,adj,vis,inRecursion))return true;
            }
            if(inRecursion[v])return true;
        }
        inRecursion[u]=false;
        return false;

    }
    bool hasCycle(int n,unordered_map<int,vector<int>>&adj){
        vector<bool>vis(n,false);
        vector<bool>inRecursion(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i] && dfsHelp(i,adj,vis,inRecursion))return true;
        }
        return false;
    }
    void dfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&vis, stack<int>&st){
        vis[u]=true;
        for(int &v:adj[u]){
            if(!vis[v])
             dfs(v,adj,vis,st);
        }
        st.push(u);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //make a graph
        unordered_map<int,vector<int>>adj;

        for(auto &vec:prerequisites){
            int a=vec[0];
            int b=vec[1];
            adj[b].push_back(a);
        }
         
        //if it has cycle return empty vector
        if(hasCycle(numCourses,adj))return {};
        vector<bool>vis(numCourses,0);
        stack<int>st;
        for(int i=0;i<numCourses;i++){
            if(!vis[i])
             dfs(i,adj,vis,st);
        }

        vector<int>result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        return result;
        

    }
};
