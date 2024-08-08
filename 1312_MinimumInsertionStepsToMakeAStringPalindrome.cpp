/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/

//M1
class Solution {
public:
    int minInsertions(string s) {
      int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[i + 1][j + 1] = s[i] == s[n - 1 - j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
        return n - dp[n][n];  
    }
};

//M2
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int l = 0; l < n - 1; ++l) {
            dp[l][l + 1] = s[l] == s[l + 1] ? 0 : 1;
        }

        for (int l = n - 3; l >= 0; --l) {
            for (int r = l + 2; r < n; ++r) {
                if (s[l] == s[r]) {
                    dp[l][r] = dp[l + 1][r - 1];
                }
                else {
                    dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
                }
            }
        }
        return dp[0][n - 1];
    }
};