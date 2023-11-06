PROBLEM:https://leetcode.com/problems/is-graph-bipartite/description
VIDEO:https://www.youtube.com/watch?v=NeU-C1PTWB8&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=16

class Solution {
public:
    bool checkBipartiteDFS(vector<vector<int>>& graph,int curr, vector<int>&color,int currColor){
        color[curr]=currColor;
        for(int &v:graph[curr]){
            if(color[v]==color[curr])return false;
            if( color[v]==-1 && checkBipartiteDFS(graph,v,color,1-currColor)==false)return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1 && checkBipartiteDFS(graph,i,color,1)==false)
             return false;
        }

        return true;
    }
};
