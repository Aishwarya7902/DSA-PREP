PROBLEM:https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/
VIDEO(MIK BHAIYA):https://www.youtube.com/watch?v=Q4bqto_yG6I&list=PLpIkg8OmuX-I_49pdy1XFY6OcATnxUrrO&index=3
Company Tags                : Similar Problem asked in Samsung
//Simply Use BFS : 
//Time  - O(m*n)
//Space - O(m+n)


class Solution {
public:
    vector<vector<int>>direction{{0,1},{0,-1},{1,0},{-1,0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();

        
        queue<pair<int,int>>q; //{i,j}
        q.push({entrance[0],entrance[1]});
        //mark it visited by making it a wall

        maze[entrance[0]][entrance[1]]='+';

        int steps=0;
        //make a classical bfs call
        while(!q.empty()){
            int size=q.size();
            while(size--){
                pair<int,int> temp=q.front();
                q.pop();
                int i=temp.first;
                int j=temp.second;
                //check if it is a boundary
                if((temp!=make_pair(entrance[0],entrance[1])) && (i==0 || i==m-1||j==0 || j==n-1))return steps;

                //explore neighbours

                for(auto &dir:direction){
                    int new_i=i+dir[0];
                    int new_j=j+dir[1];

                    if(  new_i>=0 && new_i<m && new_j>=0 && new_j<n && maze[new_i][new_j]!='+'){
                        q.push({new_i,new_j});
                        //mark visited
                        maze[new_i][new_j]='+';
                    }
                }


            }

            steps++;
        }
        return -1;
    }
};
