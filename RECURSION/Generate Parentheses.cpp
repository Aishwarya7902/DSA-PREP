Problem:https://leetcode.com/problems/generate-parentheses/
video:https://www.youtube.com/watch?v=7xkPbffc6w8&list=PLpIkg8OmuX-IBcXsfITH5ql0Lqci1MYPM&index=14

/*
  APPROACH 1
  TC:O(2^2n )
  */
class Solution {
public:
    bool isValid(string &curr){
        int cnt=0;
        for(char ch:curr){
            if(ch=='(')cnt++;
            if(ch==')')cnt--;
            if(cnt<0)return false;
        }
     return cnt==0;
    }
    void solve(string &curr,int n,vector<string>&result){
        //base case
        if(curr.size()==2*n){
            if(isValid(curr))result.push_back(curr);
            return;
        }

        
        curr.push_back('(');//try
        solve(curr,n,result);//explore
        //backtrack
        curr.pop_back();
        curr.push_back(')'); //try new possibility
        solve(curr,n,result);//explore
        curr.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string curr="";
        solve(curr,n,result);
        return result;
    }
};
