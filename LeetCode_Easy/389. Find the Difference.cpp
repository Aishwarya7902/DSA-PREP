//approach 1

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        
        for(char ch:s){
            mp[ch]++;
        }

        for(char ch:t){
            mp[ch]--;
            if(mp[ch]<0)return ch;
        }

       
     return 'x';
    }
};

//approach 2

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        int xorr=0;
        for(char &ch:s){
           xorr^=ch;
        }

        for(char ch:t){
            xorr^=ch;
        }

       
     return (char)xorr;
    }
};
