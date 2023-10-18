//QUESTION-144. Binary Tree Preorder Traversal
/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector < int > preOrder;
      if (root == NULL)
        return preOrder;

      stack < TreeNode * > s;
      s.push(root);

      while (!s.empty()) {
      TreeNode * topNode = s.top();
      preOrder.push_back(topNode -> val);
      s.pop();
      if (topNode -> right != NULL)
        s.push(topNode -> right);
      if (topNode -> left != NULL)
        s.push(topNode -> left);
        }
    return preOrder;
    };
};