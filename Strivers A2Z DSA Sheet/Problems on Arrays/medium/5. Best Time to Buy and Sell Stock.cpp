// problem :https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

/*
brute force
tc:o(n^2)
sc:o(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
         int profit=0;

         for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(prices[j]>prices[i]){
                    profit=max(profit,prices[j]-prices[i]);
                }
            }
         }
         return profit;
    }
};


/*
best
tc:o(n)
sc:o(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int mini=prices[0];
        int n=prices.size();

        for(int i=1;i<n;i++){
            profit=max(profit,prices[i]-mini);
            mini=min(mini,prices[i]);//keeping track of the minimum element so far
        }
     return profit;

    }
};
