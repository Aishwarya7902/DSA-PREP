PROBLEM :https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=K_LamGUvwUc&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=6


/*
  TC:O(V+E)
  SC:O(V+E) +O(2V) //auxiliary stack space + visited+inRecursion

  */

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool isCycleDFS(vector<int> adj[],int u,vector<bool> &visited,vector<bool> &inRecursion){
        visited[u]=true;
        inRecursion[u]=true;
        
        for(int &v:adj[u]){
            if(!visited[v] && isCycleDFS(adj,v,visited,inRecursion))
             return true;
             
            else if(inRecursion[v])
             return true;
        }
        
        inRecursion[u]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V,false);
        vector<bool>inRecursion(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i] && isCycleDFS(adj,i,visited,inRecursion))
             return true;
        }
        
        return false;
    }
};
