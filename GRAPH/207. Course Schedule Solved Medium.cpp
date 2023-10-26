PROBLEM:https://leetcode.com/problems/course-schedule/description/
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=lqjlGGMjSMU&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=12

/*
  USING BFS
  The idea is simple if graph has a cycle then we can't  finish all courses.
  So we will use topological sort for it

*/
class Solution {
public:
    int n;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //make graph
        /* Kahn's algo
         //step1: form indree
         //step2: put all with 0 indegree in queue
         //step3: do a simple bfs with a little tweak...
          tweak: moment we visit adjacent indegree v-- 
                 if indegree==0 push in queue

        */
        unordered_map<int,vector<int>>adj;
        vector<int>Indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            int v=prerequisites[i][0];
            int u=prerequisites[i][1];
            adj[u].push_back(v);
            Indegree[v]++;

        }
        queue<int>q;
        //step1 ✅

        //step2: put  vertices with indegree 0 in queue
        for(int i=0;i<numCourses;i++){
            if(Indegree[i]==0)
             q.push(i);
        }

        //do simple bfs
        int count=0;
        
        while(!q.empty()){
            int u=q.front();
            count++;
            q.pop();
            for(int &v:adj[u]){
                Indegree[v]--;
                if(Indegree[v]==0)
                 q.push(v);
            }
        }
        return count==numCourses;

        
    }
};
