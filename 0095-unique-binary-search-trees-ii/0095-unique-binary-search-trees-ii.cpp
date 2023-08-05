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
    vector<TreeNode*> generateTrees(int n) {
        function<vector<TreeNode*>(int , int)> recurr = [&](int l , int r){
           if(l > r) return vector<TreeNode*>(1,NULL);
           vector<TreeNode*>ans;
           for(int i = l;i<=r;i++){
               auto left = recurr(l, i-1);
               auto right = recurr(i+1,r);
               
             
               
               for(auto& x : left){
                   for(auto& y : right){
                       TreeNode* head = new TreeNode(i);
                       head->left = x;
                       head->right = y;
                       ans.push_back(head);
                   }
               }
           }
            
           return ans;
        };
        
        return recurr(1,n);
    }
};