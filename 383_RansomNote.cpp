/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/
//M1
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m=ransomNote.size(), n=magazine.size(),i=0, j=0;
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        while(i<m and j<n){
            if(ransomNote[i] == magazine[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return i==m?1:0;
    }
};

//M2
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> char_Count;
        for(char c: magazine) char_Count[c]++;
        for(char c:ransomNote){
            if(char_Count[c]==0) return false;
            char_Count[c]--;
        }
        return true;    }
};