/*
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring
.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/

//M1(best)
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int n = s.length(), maxLen = 0;
//         vector<int> dp(n, 0);

//         for (int i = 1; i < n; i++) {
//             if (s[i] == ')') {
//                 if (s[i - 1] == '(') {
//                     dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
//                 } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
//                     dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
//                 }
//                 maxLen = max(maxLen, dp[i]);
//             }
//         }
//         return maxLen;
//     }
// };
class Solution {
public:

    int longestValidParentheses(string s) {
        int ans=0; 
        int l=0,r=0; 
        for (int i=0;i<s.size();i++){
            if (s[i]=='(') l++; 
            else r++; 
            if (l==r) {
                ans = max(ans, 2*l); 
            }  
            if (r>l) {
                r = 0; 
                l = 0; 
            }
        }
        reverse(s.begin(),s.end()); 
        l=0,r=0; 
        for (int i=0;i<s.size();i++){
            if (s[i]==')') l++; 
            else r++; 
            if (l==r) {
                ans = max(ans, 2*l); 
            }  
            if (r>l) {
                r = 0; 
                l = 0; 
            }
        }

        return ans; 
    }
};