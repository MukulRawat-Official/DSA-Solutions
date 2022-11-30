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
typedef TreeNode node;
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
       node* curr = root;
        vector<int>ans;
        while(curr){
            if(curr->right){
              node* tmp = curr->right;
              
              while(tmp->left && tmp->left != curr) tmp = tmp->left;
              if(tmp->left == NULL){
                  tmp->left = curr;
                  ans.push_back(curr->val);
                  curr = curr->right;
              }
                
              else{
                 // ans.push_back(curr->val); // preorder
                 curr = curr->left;
                 tmp->left = NULL;
               }
            }
            
            else // right is NULL
            {
             ans.push_back(curr->val);
             curr = curr->left;
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};