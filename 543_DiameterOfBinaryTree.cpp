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
int dfs(TreeNode* root, vector<int>& res){
    if(root==NULL) return -1;
    int lh=dfs(root->left, res);
    int rh=dfs(root->right, res);
    res[0]=max(res[0],lh+rh+2);
    return 1+max(lh,rh) ;
}
    int diameterOfBinaryTree(TreeNode* root) {
        vector<int> res={0};
        dfs(root, res);
        return res[0];   
        
    }
};