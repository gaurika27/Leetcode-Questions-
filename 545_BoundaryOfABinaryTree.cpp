class Solution{
  private:
   void addLeftBoundary(Node* root, vector<int> res){
    Node* cur=root->left;
    while(cur){
      if(!isLeaf(cur)) res.push_back(cur->data);
      if(cur->left) cur= cur->left;
      else cur=cur->right;
    }
   }
  public:
   vector<int> printBoundary(Node* root){
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
   }
};