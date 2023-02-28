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
    map<string , int>mp;
    vector<TreeNode*>ans;
    
    string serialize(TreeNode* root){
        if(!root) return "#";
        
        string left = serialize(root->left);
        string right = serialize(root->right);
        
        string curr = to_string(root->val) + "/" + left + "/" + right;
        int count = (++mp[curr]);
        
        if(count == 2) ans.push_back(root);
        return curr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return ans;
    }
};