PROBLEM:https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
VIDEO (MIK BHAIYA):https://www.youtube.com/watch?v=3tgekNXWXsY&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=36

/*
  TC
  SC
  */

class Solution
{
	public:
	vector<int>parent;
	vector<int>rank;
	//DSU CODE
	
	int find(int x){
	    if(x==parent[x])return x;
	    return parent[x]=find(parent[x]);
	}
	
	void Union (int x,int y){
	    int parent_x=find(x);
	    int parent_y=find(y);
	    if(parent_x==parent_y)return;
	    
	    if(rank[parent_x]>rank[parent_y]){
	        parent[parent_y]=parent_x;
	    }
	    
	    else if(rank[parent_y]>rank[parent_x]){
	        parent[parent_x]=parent_y;
	    }
	    else{
	        parent[parent_x]=parent_y;
	        rank[parent_y]++;
	    }
	}
	int Kruskal(vector<vector<int>>&vec){
	    
	   int sum=0;
	   //now process the edges one by one
	   //TC: E*(TC of dsu which is 4*alpha)
	   for(auto &temp:vec){
	       int u=temp[0];
	       int v=temp[1];
	       int wt=temp[2];
	       
	       int parent_u=find(u);
	       int parent_v=find(v);
	       if(parent_u!=parent_v){
	           Union(u,v);
	           sum+=wt;
	       }
	   }
	   return sum;
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //making of graph
        //TC:O(V+E)
        vector<vector<int>>vec;
        for(int u=0;u<V;u++){
            for(auto &temp:adj[u]){
                int v=temp[0];
                int wt=temp[1];
                vec.push_back({u,v,wt});
            }
        }
        
        //comparator function
        auto comparator=[&](vector<int>&vec1,vector<int>&vec2){
            return vec1[2]<vec2[2];
        };
        //sort the edges in ascending order of weights;
        
        //TC:ElogE
        sort(begin(vec),end(vec),comparator);
        //resize parent and rank
        parent.resize(V);
        rank.resize(V,0);
        for(int i=0;i<V;i++)parent[i]=i;
        return Kruskal(vec);
    }
};
