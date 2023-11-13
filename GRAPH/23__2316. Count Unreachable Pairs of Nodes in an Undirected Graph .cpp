PROBLEM:https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=Hh_9ppxgzpo&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=23

/*

  DSU APPROACH
  TC:
  SC:
*/

class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    //STEP 1: writing the DSU Code
    //find function
    int find(int x){
        if(x==parent[x])
         return x;

        return parent[x]=find(parent[x]);
    }

    //Union function

    void Union(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);
        if(parent_x==parent_y)//it means dono same component me hain
         return;
        //jiska rank jyada hai usko papa baana do....but rank will remain same
        if(rank[parent_x]>rank[parent_y]){
            parent[parent_y]=parent_x;

        }

        else if(rank[parent_x]<rank[parent_y]){
            parent[parent_x]=parent_y;
        }

        //if both have same ranks .....kisi ko bhi papa bana do....aur parent ke rank ko 1 se badha do

        else{
            parent[parent_x]=parent_y;
            rank[parent_y]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        //STEP 2: making the components
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            Union(u,v);
        }

        //STEP 3: populating map...parent -> size
        unordered_map<int,int>mp;  
        for(int i=0;i<n;i++){
            int parent_i=find(i);
            mp[parent_i]++;
        }

        //find result from map

        long long result=0;
        long long remaining=n;

        for(auto &it:mp){
            //int parent_it=mp.first;
            int size=it.second;

            result+=(size)*(remaining-size);
            remaining-=size;
        }

        return result;
    }
};

/*
using dfs 
video : https://www.youtube.com/watch?v=kOt2VNsU0FE
tc
sc
*/

class Solution {
public:
    void dfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&visited,long long &size){
        visited[u]=true;
        size++;
        for(int &v:adj[u])
         if(!visited[v])
          dfs(v,adj,visited,size);
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
      //making of map
      unordered_map<int,vector<int>>adj;
      for(auto &vec:edges){
          int u=vec[0];
          int v=vec[1];
          // since it is  bidirectional graph
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
    // making of visited vector
      vector<bool>visited(n,false);

      long long remainingNodes=n;
      long long result=0;
      for(int i=0;i<n;i++){
          if(!visited[i]){
              long long size=0;
              dfs(i,adj,visited,size);
              result+=(size)*(remainingNodes-size);
              remainingNodes-=size;
          }

      }
     return result;

    }
};


/*
using bfs
video: https://www.youtube.com/watch?v=kOt2VNsU0FE
tc
sc
*/

class Solution {
public:
    void bfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&visited,long long &size){
        visited[u]=true;
        queue<int>q;
        q.push(u);
        while(!q.empty()){
            int curr=q.front();
            size++;
            q.pop();
            for(int &v:adj[curr]){
                if(!visited[v])
                {
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
      //making of map
      unordered_map<int,vector<int>>adj;
      for(auto &vec:edges){
          int u=vec[0];
          int v=vec[1];
          // since it is  bidirectional graph
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
    // making of visited vector
      vector<bool>visited(n,false);

      long long remainingNodes=n;
      long long result=0;
      for(int i=0;i<n;i++){
          if(!visited[i]){
              long long size=0;
              bfs(i,adj,visited,size);
              result+=(size)*(remainingNodes-size);
              remainingNodes-=size;
          }

      }
     return result;

    }
};
