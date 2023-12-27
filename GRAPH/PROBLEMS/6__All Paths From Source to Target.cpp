PROBLEM:https://leetcode.com/problems/all-paths-from-source-to-target/description/
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=9qWMS8GLvdI&list=PLpIkg8OmuX-I_49pdy1XFY6OcATnxUrrO&index=8
Company Tags  : Amazon, Microsoft

  /*
  TC: O(V+E) //same as dfs
  SC:
  */

  class Solution {
public:
    void dfsSolve(vector<vector<int>>& graph,int u,int target,vector<vector<int>>& result,vector<int>&temp){
        temp.push_back(u);
        if(u==target)result.push_back(temp);
        else{
            for(int &v:graph[u]){
                dfsSolve(graph,v,target,result,temp);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>result;
        vector<int>temp;
        dfsSolve(graph,0,n-1,result,temp);
        return result;
    }
};
