//https://leetcode.com/problems/valid-palindrome/description/
/*
A phrase is a palindrome if, after converting all uppercase letters into
lowercase letters and removing all non-alphanumeric characters, it reads the same 
forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
  */


class Solution {
public:
    bool helperPalindrome(string res){
        int i=0,j=res.size()-1;
        while(i<=j){
            if(res[i]!=res[j])return false;
            i++;
            j--;
        }
        return true;
    }
    bool is_alnum(char ch){
        if((ch>='A' && ch<='Z') ||
            (ch>='a' && ch<='z') ||
            (ch>='0' && ch<='9') 
        )return 1;

        return 0;

    }

    bool isUppercase(char ch){
        return ch>='A' && ch<='Z';
    }

    char to_lower(char ch){
        return ch + ('a'-'A');
    }
    bool isPalindrome(string s) {
         string res;
        // travel in the string

        for(char ch:s){
            //if current char is alpha numeric then only we will consider it
            if(is_alnum(ch)){
               // check if it is uppercase
               if(isUppercase(ch)){
                // convert to lowercase , put in result
                 res.push_back(to_lower(ch));
               }

               else{
                //if it is already a lowercase , directly push to new string
                res.push_back(ch);
               }
            }
        }

        // now we have a simple string rather than a phrase

        // simply return if it is a palindrome

        return helperPalindrome(res);


    }
};
