PROBLEM:https://leetcode.com/problems/network-delay-time/submissions/1104129047/
VIDEO:https://www.youtube.com/watch?v=hptQEIpvaxM&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=28

/*
  APPLICATION OF DIJKSTRA'S
  TC:
  SC
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        //MAKING OF GRAPH
        for(auto &vec:times){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];
            adj[u].push_back({v,wt});
        }
        //RESULT WILL STORE MIN COST TO REACH FROM SOURCE TO PARTICULAR NODE
        vector<int>result(n+1,INT_MAX);

        //PRIORITY QUEUE WILL STORE --->dist,node
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // to reach source we will nee 0 time

        result[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int time=pq.top().first;
            int node=pq.top().second;

            pq.pop();
            for(auto &it:adj[node])
            {
                int adjNode=it.first;
                int adjTime=it.second;

                if(time+adjTime<result[adjNode])
                {
                    result[adjNode]=time+adjTime;
                    pq.push({time+adjTime,adjNode});

                }
            }
        }

        // for(int i=1;i<=n;i++)
        //  if(result[i]==INT_MAX)return -1;

        int  ans=INT_MIN;
        for(int i=1;i<=n;i++)
         ans=max(ans,result[i]);
         return ans == INT_MAX ? -1 : ans;
    }
};
