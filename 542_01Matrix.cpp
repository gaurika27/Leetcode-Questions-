/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
*/
class Solution {
public:
    bool isvalid(int i, int j, int m, int n) {
        if (i == m || j == n || j < 0 || i < 0)
            return false;
        return true;
    }
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dis(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    q.push({i, j});
                    dis[i][j] = 0;
                }
            }
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (auto& x : dir) {
                int a = curr.first + x[0];
                int b = curr.second + x[1];
                if (isvalid(a, b, m, n) && dis[a][b] == -1) {
                    q.push({a, b});
                    dis[a][b] = dis[curr.first][curr.second] + 1;
                }
            }
        }
        return dis;
    }
};