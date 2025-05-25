// https://leetcode.com/problems/palindrome-number/description/

//TC : O(log n)
//SC : O(1)


class Solution {
public:
    int reverse(int x){
       int reversed=0;
       while(x){
        int last=x%10;
        if(reversed >INT_MAX/10 || (reversed==INT_MAX && last>7))return 0;
        if(reversed <INT_MIN/10 || (reversed==INT_MIN && last<-8))return 0;

        reversed=(reversed*10)+last;
        x/=10;
       }
       return reversed;

    }
    bool isPalindrome(int x) {
        if (x<0)return false;

        int reversedNumber=reverse(x);
        return (x==reversedNumber);
    }
};
