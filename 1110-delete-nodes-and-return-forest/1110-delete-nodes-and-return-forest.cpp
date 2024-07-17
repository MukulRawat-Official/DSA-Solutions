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
    vector<int>todlt;
    vector<TreeNode*> ans;
    
    TreeNode* recurr(TreeNode* root , int chk){
        if(!root) return NULL;
        
        if(chk){
            if(!todlt[root->val])    
            {
                root->left = recurr(root->left,0);
                root->right = recurr(root->right,0);
                ans.push_back(root);
                return root;
            }
            
            recurr(root->left , 1);
            recurr(root->right , 1);
            return NULL;
        }
        else
        {
            if(!todlt[root->val])    
            {
                root->left = recurr(root->left,0);
                root->right = recurr(root->right,0);
                return root;
            }
            else {
             recurr(root->left , 1);
             recurr(root->right , 1);
             return NULL;
            }
        }
        
        return NULL;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        todlt.resize(1001,0);
        for(auto& x : to_delete)  todlt[x] = 1;
        recurr(root,1);
        return ans;
    }
};