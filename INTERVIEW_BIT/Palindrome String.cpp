//https://www.interviewbit.com/problems/palindrome-string/


int Solution::isPalindrome(string A) {
    
    string B;
    for(auto ch:A){
        if((ch>='a'&& ch<='z')|| (ch>='A'&& ch<='Z') || (ch >= '0' && ch <= '9')){
            if(ch>='A'&& ch<='Z'){
                
                B.push_back(ch+32);
            }
            else
            B.push_back(ch);
        }
    }
    int left =0, right =B.size()-1;
    
    while(left<=right){
        if(B[left]!=B[right])return false;
        left++;
        right--;
    }
    return true;
}


// better code

#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string s) {
    int i = 0, j = s.size() - 1;

    while (i < j) {
        // Move i forward until alphanumeric
        while (i < j && !isalnum(s[i])) i++;
        // Move j backward until alphanumeric
        while (i < j && !isalnum(s[j])) j--;

        if (tolower(s[i]) != tolower(s[j])) {
            return 0;   // Not a palindrome
        }

        i++;
        j--;
    }

    return 1; // Palindrome
}

int main() {
    cout << isPalindrome("A man, a plan, a canal: Panama") << endl; // 1
    cout << isPalindrome("race a car") << endl;                     // 0
}
