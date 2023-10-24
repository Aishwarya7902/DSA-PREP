PROBLEM:https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
VIDEO:https://www.youtube.com/watch?v=74suJP4bwf0&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=9

/*
  TC:same as BFS
  SC: same as BFS
*/

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int count=0;
        vector<int>indegree(V,0);
        //step1.....make indegree
        for(int u=0;u<V;u++){
            for(int &v:adj[u]){
                indegree[v]++;
            }
        }
        
        //step2...put all vertices with indegree zero in queue
        
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
                
            }
        }
        
        //step3....do simple bfs
        
        while(!q.empty()){
            int curr=q.front();
            count++;
            q.pop();
            for(int &v:adj[curr]){
                indegree[v]--;
                if(indegree[v]==0)
                 q.push(v);
            }
        }
        
        if(count==V)return false;
        else
        return true;
    }
};
