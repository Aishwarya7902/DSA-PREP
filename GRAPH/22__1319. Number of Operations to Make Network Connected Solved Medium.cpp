PROBLEM:https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
VIDEO:(MIK BHAIYA)  https://www.youtube.com/watch?v=q2xBd-D_1KQ&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=22


/*
  TC:
  SC:
*/

class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    //find
    int find(int x){
        if(x==parent[x])
         return x;

        return parent[x]=find(parent[x]);
    }

    //union
    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        //already in same component
        if(x_parent==y_parent)
         return;

        //jiska rank jyada....usko papa bana do..but rank will remain same

        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        //if both have same ranks ....kisi ko bhi papa bana do....uska rank+1 kar do
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }


    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
         return -1;
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        int component=n;
        for(auto &vec:connections){
            if(find(vec[0])!=find(vec[1])){
                Union(vec[0],vec[1]);
                component--;
            }
        }

      return component-1;
    }
};
