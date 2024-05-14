PROBLEM:https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
VIDEO:https://www.youtube.com/watch?v=wXwZSytYrIs&list=PLpIkg8OmuX-IBcXsfITH5ql0Lqci1MYPM&index=10
TC:4^(N*N)
SC:O(N^2) recursive stack space


class Solution{
    public:
    bool isSafe(int i,int j,vector<vector<int>> &m, int n){
        if(i>=0 && i<n && j>=0 && j<n && m[i][j]==1)return true;
        return false;
    }
    void solve(int i,int j,vector<vector<int>> &m, int n, string &path,vector<string> &result){
        if(!isSafe(i,j,m,n))return;
        if(i==n-1 && j==n-1){
            result.push_back(path);
        }
        
        m[i][j]=0;
        //up
        if(isSafe(i-1,j,m,n)){
            path.push_back('U');
            solve(i-1,j,m,n,path,result);
            path.pop_back();
        }
        
        //down
        if(isSafe(i+1,j,m,n)){
            path.push_back('D');
            solve(i+1,j,m,n,path,result);
            path.pop_back();
        }
        
        //left
        
        if(isSafe(i,j-1,m,n)){
            path.push_back('L');
            solve(i,j-1,m,n,path,result);
            path.pop_back();
        }
        
        //right
        if(isSafe(i,j+1,m,n)){
            path.push_back('R');
            solve(i,j+1,m,n,path,result);
            path.pop_back();
        }
        //backtrack
        m[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> result;
        string path="";
        solve(0,0,m,n,path,result);
        return result;
    }
};
