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
    vector<int>arr;
    void dfs(TreeNode* root){
        if(!root) return;
       
        dfs(root->left);  arr.push_back(root->val);
        dfs(root->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root);
        auto it = lower_bound(arr.begin() , arr.end() , low);
        int ans = 0;
        while(*it != high){
            ans += *it;
            it++;
        }
        return ans + *it;
    }
};