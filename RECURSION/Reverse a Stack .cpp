PROBLEM :https://www.geeksforgeeks.org/problems/reverse-a-stack/1
VIDEO :https://www.youtube.com/watch?v=aDQeF8Izv5I&list=PLpIkg8OmuX-IBcXsfITH5ql0Lqci1MYPM&index=6

/*
  BRUTE FORCE
  TC: O(N)
  SC:O(N)
*/

class Solution{
public:
   
    void Reverse(stack<int> &St){
        if(!St.size())return;
        
        int topElement=St.top();// ek element ko nikal diya 
        St.pop();
        Reverse(St); // recursion ko ek sub problem de diya
        /*
        now recursion will provide stack like this
        3
        2
        1
        7
        
        Now we just have to add 6 in the bottom
        
        For that transfer all stack in temp...add 6 to bottom then tranfer temp in st
        */
        
        stack<int>temp;
        
        while(!St.empty()){
            temp.push(St.top());
            St.pop();
        } 
        // now St is empty...add 6 at bottom
        St.push(topElement);
        
        // transfer temp to St
         while(!temp.empty()){
            St.push(temp.top());
            temp.pop();
        } 
        
        
        
    }
};
