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
    void f(TreeNode* root){
        if(!root) return;
        arr.push_back(root->val);
        f(root->left);
        f(root->right);
    }
    int minDiffInBST(TreeNode* root) {
         f(root);
        sort(arr.begin(),arr.end());
        
        int ans = arr[1] - arr[0];
        for(int i = 2;i<arr.size();i++){
            ans = min(ans,arr[i]- arr[i-1]);
        }
        return ans;
    }
};