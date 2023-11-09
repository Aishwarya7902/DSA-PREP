PROBLEM:https://practice.geeksforgeeks.org/problems/detect-cycle-using-dsu/1
VIDEO:https://www.youtube.com/watch?v=0X0lEtTkk-8&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=20

Company Tags : Google, Microsoft

/*
  Expected Time Complexity: O(V + E)
  Expected Space Complexity: O(V)

  */

class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    vector<int>parent;
    vector<int>rank;
    
    int find(int x){
        if(x==parent[x])
         return x;
        
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        
        int parent_x=find(x);
        int parent_y=find(y);
        if(parent_x==parent_y)
          return;
          
        if(rank[parent_x]>rank[parent_y]){
            parent[parent_y]=parent_x;
        }
        
        else if(rank[parent_x]<rank[parent_y]){
            parent[parent_x]=parent_y;
        }
        
        else{
            parent[parent_x]=parent_y;
            rank[parent_y]++;
        }
    }
    
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    parent.resize(V);
	    rank.resize(V);
	    for(int i=0;i<V;i++){
	        parent[i]=i;
	        rank[i]=1;
	    }
	    
	    for(int u=0;u<V;u++){
	        for(int &v:adj[u]){
	            if(u<v){
	                int parent_u=find(u);
	                int parent_v=find(v);
	                if(parent_u==parent_v)
	                  return true;
	             
	                Union(u,v);
	            }
	        }
	    }
	    return false;
	}
};
