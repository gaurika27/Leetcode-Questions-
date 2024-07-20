/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 
*/

//M1
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int Triangle_size=triangle.size();
        vector<int> minimum_pathsum=triangle[Triangle_size-1];
        for(int i=Triangle_size-2; i>=0; --i){
            for(int j=0; j<triangle[i].size(); ++j){
               minimum_pathsum[j]=triangle[i][j]+min(minimum_pathsum[j],minimum_pathsum[j+1]); 
            }
        }
        return minimum_pathsum[0];
        
    }
};

//M2
class Solution {
    public:
        int minimumTotal(vector<vector<int>>& arr) {
            for (int i=arr.size()-2;i>=0;i--) 
                for (int j=0;j<arr[i].size();j++) 
                    arr[i][j] += min(arr[i+1][j], arr[i+1][j+1]);
            return arr[0][0];
        }
};
