class Solution{
  public:
   vector<int> printBoundary(Node* root){
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    addLeftBoundary(root, res);
    addRightBoundary(root, res);
    return res;
   }
};