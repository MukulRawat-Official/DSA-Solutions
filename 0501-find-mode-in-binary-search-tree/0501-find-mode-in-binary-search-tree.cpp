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
    int num , f , mf = 0;
    vector<int>arr;
    void dfs(TreeNode* curr){
        if(!curr) return;
        dfs(curr->left);
        if(num == curr->val || num == 1e6)   f++;    
        else {
            if(f > mf) {
                mf = f; 
                arr.clear();
            }
            if(f == mf) arr.push_back(num);
            f = 1;
        }
        num = curr->val;
        dfs(curr->right); 
    }
    vector<int> findMode(TreeNode* root) {
        num = 1e6;
        f = 0;
        dfs(root);
        if(f > mf) { mf = f; arr.clear();}
        if(f == mf) arr.push_back(num);
        return arr;
    }
};