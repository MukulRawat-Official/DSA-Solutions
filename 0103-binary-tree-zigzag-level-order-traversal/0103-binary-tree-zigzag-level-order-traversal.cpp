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
    vector<vector<int>>ans;
    void f(TreeNode* root , int lvl){
        if(!root) return;
        
        if(lvl == ans.size()) ans.push_back(vector<int>());
        ans[lvl].push_back(root->val);
         
        f(root->left,lvl+1);
        f(root->right,lvl+1);
        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     
        f(root, 0);
        
        for(int i =1;i<ans.size();i+=2){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};