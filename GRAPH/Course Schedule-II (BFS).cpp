PROBLEM:https://leetcode.com/problems/course-schedule-ii/
VIDEO:https://www.youtube.com/watch?v=W1WhSN9wAw0&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=13

/*
  TC
  SC
*/


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>result;
        //make graph...step1
        //make indegree....step2
        //put all with indgree 0 in queue...step3
        //do simple bfs
        unordered_map<int,vector<int>>adj;
        vector<int>Indegree(numCourses,0);
        //.........step1
        for(int i=0;i<prerequisites.size();i++){
            int v=prerequisites[i][0];
            int u=prerequisites[i][1];
            adj[u].push_back(v);
            //step2
            Indegree[v]++;
        }

        // step3
        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(Indegree[i]==0)
            {
                q.push(i);
            }
        }


        //step4
        int cnt=0;

        while(!q.empty()){

            int u=q.front();
            result.push_back(u);
            cnt++;
            q.pop();
            for(int &v:adj[u]){
                Indegree[v]--;
                if(Indegree[v]==0)
                 q.push(v);
            }
        }
        //if it is possible to make a topo sort only then we can return some order ....else we return an empty vector
        if(cnt==numCourses) return result ;
        return {};
    }
};
