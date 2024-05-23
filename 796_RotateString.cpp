/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
 

Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.
*/
class Solution {
public:
    void rotate(string &v, int x,int y){
        for(int i=x,j=y;i<=j;i++,j--){
            swap(v[i],v[j]);
        }
    }
    bool rotateString(string s, string g) {
        string k=s;
        for(int i=0;i<s.size();i++){
            s=k;
            rotate(s,s.size()-i,s.size()-1);
            rotate(s,0,s.size()-1-i);
            rotate(s,0,s.size()-1);
            if(s==g) return true;
        }
    return false;
    }
};