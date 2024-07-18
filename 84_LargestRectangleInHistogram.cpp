/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

//M1
class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int maxArea = 0;
    stack<int> s; // Stores indices of elements

    for (int i = 0; i < n; i++) {
      while (!s.empty() && heights[i] < heights[s.top()]) {
        int top = s.top();
        s.pop();
        int width = (s.empty()) ? i : (i - s.top() - 1);
        maxArea = max(maxArea, heights[top] * width);
      }
      s.push(i);
    }

    // Handle remaining elements after the loop
    while (!s.empty()) {
      int top = s.top();
      s.pop();
      int width = (s.empty()) ? n : (n - s.top() - 1);
      maxArea = max(maxArea, heights[top] * width);
    }

    return maxArea;
  }
};
