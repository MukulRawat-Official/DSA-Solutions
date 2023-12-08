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
    string dfs(TreeNode* root)
    {
          if(!root) return "";
         
          string t = "" + to_string(root->val);
         
         
          if(root->left)  {
              t += "(" + dfs(root->left) + ")";
             if(root->right)
                 t += "(" + dfs(root->right) + ")";
          }
          else if(root->right) t += "()(" + dfs(root->right) + ")";
        
         return t;
        
    }
    string tree2str(TreeNode* root) {
        return dfs(root);   
    }
};