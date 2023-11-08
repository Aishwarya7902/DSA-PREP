PROBLEM :https://leetcode.com/problems/satisfiability-of-equality-equations/description/
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=0Z8lt7U_kiE&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=21

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

    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);

        if(x_parent==y_parent)
         return;

        if(rank[x_parent]>rank[y_parent])
          parent[y_parent]=x_parent;
        else if(rank[x_parent]<rank[y_parent])
         parent[x_parent]=y_parent;
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }


    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++){
           parent[i]=i; 
        }

        // first do union of equal chars.....like a==b
        for(string &s:equations){
            if(s[1]=='='){
                Union(s[0]-'a',s[3]-'a');
            }
        }

        // check for a!=b cases

        for(string &s:equations){
            if(s[1]=='!'){
                int first=s[0];
                int second=s[3];
                int parent_first=find(first-'a');
                int parent_second=find(second-'a');
                if(parent_first==parent_second)
                 return false;
            }
        }

        return true;
        
    }
};
