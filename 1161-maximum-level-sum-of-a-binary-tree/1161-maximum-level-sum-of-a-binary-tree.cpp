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
    int maxLevelSum(TreeNode* root) {
        int ans = root->val , curr , lvl = 0 , res_lvl = 1;
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.size()){
            int sz = q.size();
            curr =0;
            lvl++;
            while(sz--){
             TreeNode* tmp = q.front(); q.pop();
             curr += tmp->val;
             if(tmp->left) q.push(tmp->left); 
             if(tmp->right) q.push(tmp->right); 
            }
            
            if(curr > ans){
                ans = curr;
                res_lvl = lvl;
            }
        }
        
        return res_lvl;
        
    }
};