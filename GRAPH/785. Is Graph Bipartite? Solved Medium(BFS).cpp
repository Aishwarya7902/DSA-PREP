PROBLEM:https://leetcode.com/problems/is-graph-bipartite/
VIDEO:https://www.youtube.com/watch?v=cvhXZt66VhA&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=17

class Solution {
public:
    bool checkBipartiteBFS(vector<vector<int>>& graph,int curr,vector<int>&color,int currColor){
        color[curr]=currColor;
        queue<int>q;
        q.push(curr);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int  &v:graph[u]){
                if(color[u]==color[v])return false;

            else if(color[v]==-1 ){
                color[v]=1-color[u];
                q.push(v);
            }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
       int v=graph.size();
       vector<int>color(v,-1);
       for(int i=0;i<v;i++){
           if(color[i]==-1 && checkBipartiteBFS(graph,i,color,1)==false)return false;
       } 
       return true;
    }
};
