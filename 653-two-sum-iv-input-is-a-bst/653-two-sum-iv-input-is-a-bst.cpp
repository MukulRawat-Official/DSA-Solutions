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
    map<int,int>m;
    
    bool in(TreeNode* root,int k)
    {
        if(!root) return false;
        
        bool ans = in(root->left,k);
        if(m.size() && m.count(k - root->val)) return 1;
        m[root->val]++;
        ans |= in(root->right,k);
        
        return ans;
        
    }
    bool findTarget(TreeNode* root, int k) {
        return in(root,k);
    }
};