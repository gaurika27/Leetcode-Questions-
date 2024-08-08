/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 
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
// class Solution {
// public:
//     void pre_order_traversal(TreeNode* root, vector<int> &v){
//         if(!root) return;
//         v.push_back(root->val);
//         pre_order_traversal(root->left, v);
//         pre_order_traversal(root->right, v);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> v;
        
//         //preorder:root, left, right
//         pre_order_traversal(root,v);
//         sort(v.begin(), v.end());
//         return v[k-1];        
//     }
// };


// class Solution {
// public:
//     void in_order_traversal(TreeNode* root, vector<int> &v){
//         if(!root) return;

//         in_order_traversal(root->left, v);
//         v.push_back(root->val);
//         in_order_traversal(root->right, v);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> v;
        
//         //inorder:root, left, right
//         in_order_traversal(root,v);
       
//         return v[k-1];        
//     }
// };

class Solution {
public:
    void solve(TreeNode* root, int &count, int &ans, int k){
        if(!root) return;

        //left, root, right
        solve(root->left, count, ans, k);
        count++;
        if(count==k){
            ans=root->val;
            return;
        }
        solve(root->right, count, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0, ans;

        solve(root, count, ans, k);
        return ans;        
    }
};



