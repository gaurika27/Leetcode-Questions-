/*
The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

 

Example 1:

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
Example 2:

Input: s = "aabcbaa"
Output: 17
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.
*/

class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        int n=s.length();
        for(int i=0; i<n; i++){
        unordered_map<char, int> mpp;
        for(int j=i; j<n; j++){
            mpp[s[j]]++;
        int maxx=0, minn=INT_MAX; 
        for(auto it:mpp){
            maxx=max(maxx, it.second);
            minn=min(minn, it.second);
        }
        sum+=(maxx-minn);
        }

        }
        return sum;
        
    }
};