int ans;
class Solution {
    int height(TreeNode *root){
        if(root == NULL) return 0;
        int h = 1;
        while(root->left){            // OPTIMISED HEIGHT CALCULATION BCOZ 
            root = root->left; h++;   // OF THE "COMPLETE BINARY TREE PROPERTY"
		}                             // Credit:  @user1132rN
        return h;
    }
public:
    int countNodes(TreeNode* root, int cur = 1) {
        ans = 0;
        if(root == NULL) return 0;
        int lh = height(root->left), rh = height(root->right);
        if(rh == 0)
            if(root->left != NULL) ans = cur*2;
            else ans = cur;
        else
            if(lh == rh) countNodes(root->right, cur*2 + 1);
            else countNodes(root->left, cur*2);
        
        return ans;
    }
};