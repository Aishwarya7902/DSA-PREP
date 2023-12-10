PROBLEM:https://leetcode.com/problems/min-cost-to-connect-all-points/
VIDEO(MIK BHAIYA) :https://www.youtube.com/watch?v=hsr7KolYDH0&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=35

/*
  TC: same as prims
  SC:
  */


class Solution {
public:
    typedef pair<int,int>P;
    int primsAlgo(int V,vector<vector<P>>&adj){

        priority_queue<P,vector<P>,greater<P>>pq;
      vector<bool>inMST(V,false);
        pq.push({0,0});
        int sum=0;

        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int wt=curr.first;
            int node=curr.second;

            if(inMST[node]==true)continue;
            sum+=wt;
            inMST[node]=true;
            for(auto &it:adj[node]){
                int neighbour=it.first;
                int neighbour_wt=it.second;

                if(inMST[neighbour]==false){
                    pq.push({neighbour_wt,neighbour});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        vector<vector<P>>adj(V);
        //making of graph

        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                int dist=abs(x1-x2)+abs(y1-y2);

                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }
        return primsAlgo(V,adj);

    }
};

