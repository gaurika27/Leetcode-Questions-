/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105
*/

//M1-Recursion but TLE occurs
class Solution {
public:
    int f(int ind, int buy, int cap, vector<int>& prices, int n){
        if(ind==n || cap==0) return 0;
        if(buy==1){
            return max((-prices[ind]+f(ind+1, 0, cap, prices, n)),
                       (0+ f(ind+1, 1, cap, prices, n)));
        }else{
            return max((prices[ind]+f(ind+1, 1, cap-1, prices, n)),
                       (0+ f(ind+1, 0, cap, prices, n)));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2, vector<int>(3,0)));
        return f(0,1,2,prices,n);

        
    }
};

//M2-DP Memoization
class Solution {
public:
    int f(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (ind == prices.size() || cap == 0) return 0;

        if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        int profit = 0;
        if (buy == 1) {
            profit = max(-prices[ind] + f(ind + 1, 0, cap, prices, dp),
                         0 + f(ind + 1, 1, cap, prices, dp));
        } else {
            profit = max(prices[ind] + f(ind + 1, 1, cap - 1, prices, dp),
                         0 + f(ind + 1, 0, cap, prices, dp));
        }

        return dp[ind][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};
