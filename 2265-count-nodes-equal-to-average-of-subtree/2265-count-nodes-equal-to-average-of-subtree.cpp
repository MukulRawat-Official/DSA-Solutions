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
    int ans = 0;
    pair<int,int> dfs(TreeNode* root){
        if(!root) return {0,0};
        pair<int,int> res = {root->val , 1};
        auto tmp = dfs(root->left);
        auto tmp2 = dfs(root->right);
        res.first += tmp.first + tmp2.first;
        res.second += tmp.second + tmp2.second;
        ans += (root->val == res.first / res.second);
        return res;
    }
    
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};