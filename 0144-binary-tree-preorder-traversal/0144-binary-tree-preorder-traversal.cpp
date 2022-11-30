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
    vector<int> preorderTraversal(TreeNode* root) {
 node* curr = root;
        vector<int>ans;
        while(curr){
            if(curr->left){
              node* tmp = curr->left;
              
              while(tmp->right && tmp->right != curr) tmp = tmp->right;
              if(tmp->right == NULL){
                  tmp->right = curr;
                  ans.push_back(curr->val);
                  curr = curr->left;
              }
                
              else{
                 // ans.push_back(curr->val); // preorder
                 curr = curr->right;
                 tmp->right = NULL;
               }
            }
            
            else // left is NULL
            {
             ans.push_back(curr->val);
             curr = curr->right;
            }
        }
        
        return ans;
    }
};