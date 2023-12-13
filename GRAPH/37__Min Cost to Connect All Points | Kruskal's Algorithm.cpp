PROBLEM :https://leetcode.com/problems/min-cost-to-connect-all-points/
VIDEO (MIK BHAIYA): https://www.youtube.com/watch?v=O6wQQtv71S0&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=37

/*
  TC
  SC
  */

class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x==parent[x])return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);
        if(parent_x==parent_y)return;

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
    int Kruskal(vector<vector<int>>&vec){
        int sum=0;
        //now process the edges
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        parent.resize(V);
        rank.resize(V,0);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        vector<vector<int>>vec;
        // making of graph
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                int dist=abs(x1-x2)+abs(y1-y2);
                vec.push_back({i,j,dist});

            }
        }
         auto comparator=[&](vector<int>&vec1,vector<int>&vec2){
             return vec1[2]<vec2[2];
         };

        sort(begin(vec),end(vec),comparator);
        return Kruskal(vec);
    }
};
