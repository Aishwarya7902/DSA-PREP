// https://leetcode.com/problems/reverse-integer/description/

// TC : O(logn)

class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        while (x) {
            int lastDigit = x % 10;
            x /= 10;
            // Check for overflow before multiplying
            
            if (reverse > INT_MAX / 10 ||
                (reverse == INT_MAX / 10 && lastDigit > 7))
                return 0;
            if (reverse < INT_MIN / 10 ||
                (reverse == INT_MIN / 10 && lastDigit < -8))
                return 0;

            reverse = (reverse * 10) + lastDigit;
        }

        return reverse;
    }
};
