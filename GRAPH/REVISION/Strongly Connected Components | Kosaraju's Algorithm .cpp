/*
Company Tags : Amazon, Visa
Question Link : https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
Video Link (Mik Bhaiya):https://www.youtube.com/watch?v=E6DeC0Zpdns&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=38
*/

class Solution
{
	public:
	void dfsTopo(int u,vector<vector<int>>& adj, vector<bool>&visited,stack<int>&st){
	    visited[u]=true;
	    for(int &v:adj[u]){
	        if(!visited[v])
	         dfsTopo(v,adj,visited,st);
	    }
	    st.push(u);
	}
	void dfsTraversal(int u,vector<vector<int>>& adjReverse, vector<bool>&visited){
	    visited[u]=true;
	    for(int &v:adjReverse[u]){
	        if(!visited[v])
	         dfsTraversal(v,adjReverse,visited);
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        
        //STEP 1: store order of dfs in stack.....Topo sort
        
        stack<int>st;
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i])
             dfsTopo(i,adj,visited,st);
        }
        
        //STEP 2 : reverse the graph
        vector<vector<int>> adjReverse(V);
        for(int u=0;u<V;u++){
            for(int &v:adj[u]){ //adj has u->v ...in reverse graph we have to make v->u
                adjReverse[v].push_back(u);
            }
        }
        
        //STEP 3: CALL DFS BASED ON STACK ORDER
        int countScc=0;
         visited = vector<bool>(V, false);
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!visited[node]){
                dfsTraversal(node,adjReverse,visited);
                countScc++;
            }
        }
        return countScc;
        
    }
};
