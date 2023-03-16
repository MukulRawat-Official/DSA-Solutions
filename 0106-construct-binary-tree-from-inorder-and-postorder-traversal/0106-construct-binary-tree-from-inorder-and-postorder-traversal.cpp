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
    node* recurr(vector<int>&in, vector<int>&post,int l ,int r , int& pi)
    {
        if(l>r || pi == 0) return NULL;
        
        int idx = l;
        for(int i = l;i<=r;i++)
        {
            if(in[i] == post[pi-1])
            {
                idx = i;
                break;
            }
        }
        pi--;
        
        node* curr = new node(in[idx]);
        
        curr->right = recurr(in,post,idx+1,r,pi);
        curr->left = recurr(in,post,l,idx-1,pi);
        
        return curr;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int idx = in.size();
        return recurr(in,post,0,in.size()-1,idx);
    }
};