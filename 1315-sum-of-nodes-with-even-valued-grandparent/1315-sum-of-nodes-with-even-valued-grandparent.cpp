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
    int dfs (TreeNode* root , int lvl , int prev , int prev2){
       if(!root) return 0;
        
       int ans = dfs(root->left,lvl+1,root->val,prev) +  dfs(root->right,lvl+1,root->val,prev);
       if( lvl > 1 && prev2 % 2 == 0) ans += root->val;
       return ans;
    }
    int sumEvenGrandparent(TreeNode* root) {
       return dfs(root,0,-1,-1);
     }
};