//Balanced BT-> for every node=height(left)-height(right)
/*PSEUDOCODE for O(N^2)
bool check(Node)
  if node==null
    return true

  lh=findHleft(node->left)
  rh=findHright(node->right)

  if(abs(rh-lh)>1) return false;
  
  bool left=check(node->left)
  bool right=check(node->right)
  
  if(!left||!right) return false;

  return true;

*/

/* PSEUDOCODE For O(N)
int check(node){
  if(node==NULL)
    return 0

  lh=check(node->left)
  rh=check(noe->right)
  
  if(lh==-1 || rh==-1) return -1
  if(abs(lh-rh)>1) return -1;
  
  return max(lh,rh)+1;
}
*/

/*
Given a binary tree, determine if it is 
height-balanced
.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
*/

