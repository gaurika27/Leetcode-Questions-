/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100

*/
//M1
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int resultant_sums=0;
        for(auto i:nums) resultant_sums+=i;
        if(resultant_sums%2) return false;
        resultant_sums/=2;
        vector<bool> dp(resultant_sums+1, false);
        dp[0]=true;
        for(auto x:nums){
            for(int i=resultant_sums; i>=x; i--){
                dp[i]=dp[i] || dp[i-x];
            }
        }
        return dp[resultant_sums];    
    }
};

//M2
class Solution {
public:
    int init = []{
        ios_base::sync_with_stdio(false);
        return 0;
    }();

    bool canPartition(vector<int>& nums) {
        int sum = 0; 
        for (int i:nums) sum += i; 
        if (sum & 1) return false; 
        bitset<200/2*100 +1> dp(0);
        
        dp[0] = 1;
        for (int i: nums){
            dp |= dp << i;
            if (dp[sum/2]) return true;
        }
        return dp[sum/2]; 
    }
};