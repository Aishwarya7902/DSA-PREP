PROBLEM:https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
VIDEO (MIK BHAIYA):https://www.youtube.com/watch?v=V9gXzD7g8fw&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=34

/*
  TC:
  SC:
*/

class Solution
{
	public:
	typedef pair<int,int>P;
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<P,vector<P>,greater<P>>pq;
        //{wt,node}
        
        pq.push({0,0});
        vector<bool>inMST(V,false);
        int sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int wt=it.first;
            int node=it.second;
            if(inMST[node]==true)continue;
            sum+=wt;
            inMST[node]=true;
            for(auto &vec:adj[node]){
                int neighbour=vec[0];
                int neighbour_wt=vec[1];
                if(inMST[neighbour]==false){
                    pq.push({neighbour_wt,neighbour});
                }
            }
        }
        return sum;
    }
};
