/**
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).


Idea:
The idea is from dynamic programming, the max profit at day i is the max profit before 
day i + max profit after day i. So there is one loop O(n) to compute the max profit 
before each each day and another loop O(n) to get the final max profit by compute the max 
profit after each day reversely and combine the "before day" max profit.
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int mprof = 0;
        if (prices.size()>1){
            vector<int> mp; // max profit before each element
            mp.push_back(0);
            int st = *prices.begin();
            for(int i = 1 ; i< prices.size();i++){  //compute mp vector
                if (mprof < prices[i]-st){
                	mprof = prices[i]-st;
                }
                if (prices[i]<st){
                	st = prices[i];
                }
                mp.push_back(mprof);
            }
            mprof = 0;
            int ed = *(prices.end()-1);
            for (int i = prices.size()-2; i>=0; i--){
                if (mprof < ed - prices[i] + mp[i]) { 
                	mprof = ed - prices[i] + mp[i];
                }
                if (prices[i]>ed) {
                	ed = prices[i];
                }
            }
        }
        return mprof;
    }
};