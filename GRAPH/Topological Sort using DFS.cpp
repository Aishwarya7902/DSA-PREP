PROBLEM:https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

VIDEO:https://www.youtube.com/watch?v=WbbYZRr4arw&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=7

/*
  TC:O(V+E)
  SC:O(V+E)
*/

class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	
	void helperDFS(int u,vector<int> adj[],vector<bool>&visited,stack<int>&st){
	   visited[u]=true;
	   for(int &v:adj[u]){
	       if(!visited[v])
	        helperDFS(v,adj,visited,st);
	   }
	   st.push(u);
	}
	
	//
	vector<int> topoSort(int V, vector<int> adj[]){
	    // code here
	    vector<int> result;
	    vector<bool>visited(V,false);
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(!visited[i])
	         helperDFS(i,adj,visited,st);
	    }
	    
	    while(!st.empty()){
	        result.push_back(st.top());
	        st.pop();
	    }
	    return result;
	}
};
