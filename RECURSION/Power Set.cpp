PROBLEM :https://www.geeksforgeeks.org/problems/power-set4302/1
VIDEO :https://www.youtube.com/watch?v=tp9Y2AqBk6s&list=PLpIkg8OmuX-IBcXsfITH5ql0Lqci1MYPM&index=15

/*
  TC:O(n*(2^n)) .... //tc: every place has 2 choices ...and then *n coz we are pushing curr into result
  */

class Solution{
	public:
	    void solve(string s,int indx,string &curr,vector<string>&result){
	        if(indx>=s.size()){
	            if(curr!=""){
	                result.push_back(curr);
	                
	            }
	         return;   
	        }
	        
	        curr.push_back(s[indx]);
	        solve(s,indx+1,curr,result);
	        
	        //backtrack
	        
	        curr.pop_back();
	        solve(s,indx+1,curr,result);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> result;
		    string curr="";
		    solve(s,0,curr,result);
		    sort(result.begin(),result.end());
		    return result;
		}
};
