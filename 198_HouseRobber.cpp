/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

//M1_Memoization

class Solution {
public:
    int f(int ind, vector<int> &nums, vector<int> &dp){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int pick=nums[ind]+f(ind-2, nums, dp);
        int notpick=0+f(ind-1, nums, dp);

        return dp[ind]= max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(n-1, nums, dp);
        
    }
};

//M2_Tabulation

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Base cases for handling empty array (n=0) and single house (n=1)
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Create a dp vector to store maximum stolen value at each house
        vector<int> dp(n, 0);

        // Initialize dp[0] with the first house's value
        dp[0] = nums[0];

        // Loop through remaining houses (i=1 to n-1)
        for (int i = 1; i < n; i++) {
            // Consider including the current house (pick)
            int pick = nums[i];

            // If there are at least two houses before (i>=2), add the non-adjacent house's value (dp[i-2])
            if (i > 1) {
                pick += dp[i - 2];
            }

            // Consider excluding the current house (notpick) and take the previous house's value
            int notPick = dp[i - 1];

            // Store the maximum value (including or excluding current house) in dp[i]
            dp[i] = max(pick, notPick);
        }

        // Return the maximum stolen value from the last house (dp[n-1])
        return dp[n - 1];
    }
};
