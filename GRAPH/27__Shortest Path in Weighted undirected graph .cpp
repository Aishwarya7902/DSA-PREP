PROBLEM:https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=icVJUN45f1E&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=27

/*
  
  Expected Time Complexity: O(m* log(n))
  Expected Space Complexity: O(n)

  */

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        //MAKING OF GRAPH
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>result(n+1,INT_MAX);
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        
        
       
        
        result[1]=0;
        pq.push({0,1});
        
        while(!pq.empty()){
            
            int dist=pq.top().first;
            int Node=pq.top().second;
            
            pq.pop();
            for(auto &it:adj[Node]){
                
                int adjNode=it.first;
                int adjDist=it.second;
                
                if(dist+adjDist<result[adjNode]){
                    result[adjNode]=dist+adjDist;
                    pq.push({dist+adjDist,adjNode});
                    parent[adjNode]=Node;
                }
            }
        }
        
        int destNode=n;
        if(result[destNode]==INT_MAX)
         return {-1};
         
        vector<int>path;
        while(parent[destNode]!=destNode){
            path.push_back(destNode);
            destNode=parent[destNode];
        }
        path.push_back(destNode);
        reverse(begin(path),end(path));
        return path;
        
    }
};
