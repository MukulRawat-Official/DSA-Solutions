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
    int prv = -1;
    int dfs(TreeNode* root)
    {
       if(!root) return 1e6;
       
       int ans = 1e6;
       ans = dfs(root->left);
        if(prv != -1)
       ans = min(ans , abs(root->val  - prv));
       prv = root->val;
       ans = min(ans,dfs(root->right));  
       return ans;
    }
    int getMinimumDifference(TreeNode* root) {
        return dfs(root);
    }
};