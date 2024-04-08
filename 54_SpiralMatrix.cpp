/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();     
    int n = matrix[0].size();
    int minR = 0;
    int maxR = m-1;
    int minC = 0 ;
    int maxC = n-1 ;
    vector<int> ans;
    while(minR<=maxR && minC<=maxC)
    { 
        // go right 
        for(int j = minC ; j<=maxC; j++)
           {
               ans.push_back(matrix[minR][j]);
           }
           minR++;
       if(minR>maxR || minC>maxC) break;

       // go down 
            for(int i = minR ; i<=maxR; i++)
           {
               ans.push_back(matrix[i][maxC]);
           }
         maxC--;
         if(minR>maxR || minC>maxC) break;

         // go left
         for(int j = maxC ; j>=minC; j--)
           {
               ans.push_back(matrix[maxR][j]);
           }
           maxR--;
            if(minR>maxR || minC>maxC) break;

            //go up
           for(int i = maxR ; i>=minR; i--)
           {
               ans.push_back(matrix[i][minC]);
           }
           minC++;
         if(minR>maxR || minC>maxC) break;

    }    
  return ans;
    }
};