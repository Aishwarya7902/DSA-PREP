PROBLEM :https://leetcode.com/problems/sum-of-distances-in-tree/description/
VIDEO (MIK BHAIYA):https://www.youtube.com/watch?v=b6DrMMHFiL0&list=PLpIkg8OmuX-I_49pdy1XFY6OcATnxUrrO&index=7
Problem Name : Sum of Distances in Tree (HARD)
Company Tags  : Google
//Time : O(n), Space : O(n)

class Solution {
public:
    long root_result=0;
    vector<int>count;
    int N;

    void DFS(unordered_map<int,vector<int>>&adj,int curr,int prev,vector<int>&result){
        for(int &child:adj[curr]){
            if(child==prev)continue;

            result[child]=result[curr]-count[child]+(N-count[child]);
            DFS(adj,child,curr,result);
        }
    }
    int dfsRoot(unordered_map<int,vector<int>>&adj,int currNode,int prevNode,int currDepth){
        int total_count=1;
        root_result+=currDepth;

        for(int &child:adj[currNode]){
            if(child==prevNode)continue;

            total_count+=dfsRoot(adj,child,currNode,currDepth+1);
        }

        count[currNode]=total_count;
        return total_count;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N=n;
        count.resize(n,0);
        unordered_map<int,vector<int>>adj;

        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        root_result=0;
        dfsRoot(adj,0,-1,0);
        vector<int>result(n,0);
        result[0]=root_result;

        DFS(adj,0,-1,result);
        return result;
    }
};
