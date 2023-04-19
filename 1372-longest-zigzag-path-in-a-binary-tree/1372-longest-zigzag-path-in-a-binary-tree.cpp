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
    pair<int,int> dfs(TreeNode* root , int& ans){
        if(!root) return {0,0};
        
        pair<int,int> l = dfs(root->left, ans);
        pair<int,int> r = dfs(root->right,ans);
        
        ans = max({ans , l.first , l.second + 1 , r.first + 1, r.second});
        
        return {l.second+1, r.first + 1};
    }
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        dfs(root,ans);
        return max(ans-1,0);
    }
};