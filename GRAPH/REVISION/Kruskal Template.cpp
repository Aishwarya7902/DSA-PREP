//Note the code is after sorting the edges in ascending order of their weights.
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
