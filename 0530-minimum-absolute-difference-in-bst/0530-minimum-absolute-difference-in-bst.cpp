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
    int dfs(TreeNode* root , int& prv)
    {
       if(!root) return 1e6;
       
       int ans = 1e6;
       ans = dfs(root->left , prv);
        if(prv != -1)
       ans = min(ans , abs(root->val  - prv));
       prv = root->val;
       ans = min(ans,dfs(root->right , prv));  
       return ans;
    }
    int getMinimumDifference(TreeNode* root) {
        int prv = -1;
        return dfs(root , prv);
    }
};