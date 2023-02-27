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
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       TreeNode* head  = new TreeNode(preorder[0]);
        
       auto insert = [](TreeNode* head , int val,auto&& insert)->void
       {
            if(head->val < val){
                if(head->right) insert(head->right,val,insert);
                else {
                    head->right = new TreeNode(val);
                    return;
                }
            }
           
           else{
               if(head->left) insert(head->left,val,insert);
                else {
                    head->left = new TreeNode(val);
                    return;
                }
           }
       };
        
        for(int i = 1;i<preorder.size();i++){
            insert(head,preorder[i],insert);
        }
        
        return head;
    }
};