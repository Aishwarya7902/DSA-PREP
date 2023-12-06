PROBLEM:https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
VIDEO:https://www.youtube.com/watch?v=5yTkgeTqKK0&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=31

/*
  TC:O(E*V)
  SC:O(1)
  */

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        
        vector<int>result(V,1e8);
        //Bellman says ...relax v-1 times
        result[S]=0;
        for(int count=1;count<=V-1;count++){
            for(auto &edge:edges){
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];
                if(result[u]!=1e8){
                    if(result[u]+wt<result[v]){
                        result[v]=result[u]+wt;
                    }
                }
            }
        }
        
        //now to check negative cycle...relax just one more time
        
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            
            if(result[u]!=1e8){
                if(result[u]+wt<result[v]){
                    result[v]=result[u]+wt;
                    return {-1};
                }
            }
        }
        return result;
    }
};
