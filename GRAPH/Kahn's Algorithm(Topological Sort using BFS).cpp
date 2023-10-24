PROBLEM:https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
VIDEO:https://www.youtube.com/watch?v=uVl4ftleTes&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=8

/*
  TC:same as bfs
  SC:same as bfs
*/

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	    	vector<int>result;
	    	
	    	vector<int>Indegree(V,0);
	    	//step1 ..making of Indegrees
	    	for(int u=0;u<V;u++){
	    	    for(int &v:adj[u]){
	    	        Indegree[v]++;
	    	    }
	    	}
	    	
	    	//step2..put all vertices with indegree 0 into the queue
	    	
	    	queue<int>q;
	    	for(int i=0;i<V;i++){
	    	    if(Indegree[i]==0)
	    	     q.push(i);
	    	}
	    	
	    	//step3...do simple bfs
	    	
	    	while(!q.empty()){
	    	    int u=q.front();
	    	    result.push_back(u);
	    	    q.pop();
	    	    for(int &v:adj[u]){
	    	        Indegree[v]--;
	    	        if(Indegree[v]==0)
	    	         q.push(v);
	    	    }
	    	}
	    	return result;
	    
	}
};
