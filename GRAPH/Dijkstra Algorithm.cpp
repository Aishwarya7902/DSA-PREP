PROBLEM:https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
VIDEO:https://www.youtube.com/watch?v=xQ3vjWwFRuI&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=25

/*
  TC:
  SC:

*/

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int source)
    {
        // Code here
        vector <int>result(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        result[source]=0;
        pq.push({0,source});
        
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            
            pq.pop();
            
            //exploring adjacent nodes
            for(auto &vec:adj[node]){
                int adjNode=vec[0];
                int adjDist=vec[1];
                
                if(d+adjDist<result[adjNode]){
                    result[adjNode]=d+adjDist;
                    pq.push({d+adjDist,adjNode});
                }
            }
        }
        
        return result;
        
    }
};
