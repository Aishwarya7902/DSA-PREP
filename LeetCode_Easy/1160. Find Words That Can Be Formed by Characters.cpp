PROBLEM :https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/

/*
  METHOD 1
  TC:
  SC:
*/

class Solution {
public:
    bool hasMade(string s,vector<int>&charCount){
      vector<int>wordCount(26,0);
      for(char &ch:s){
        wordCount[ch-'a']++;
      }
      
      for(int i=0;i<26;i++){
        if(wordCount[i]>charCount[i]){
           return false;
        }
      }
      return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        int result=0;
        vector<int>charCount(26,0);
        for(char &ch:chars){
            charCount[ch-'a']++;
        }


        for(int i=0;i<words.size();i++){
            if(hasMade(words[i],charCount)){
                cout<<words[i];
                result+=words[i].size();
            }
        }

        return result;
    }
};
