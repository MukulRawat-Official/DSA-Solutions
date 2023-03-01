/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        
        string lft = serialize(root->left);
        string rt = serialize(root->right);
        string curr = to_string(root->val) + "#" + lft + rt; 
        return curr;
    }

    // Decodes your encoded data to tree.
    

    TreeNode* deserialize(string data) {
      if(data.size() == 0) return NULL;
      vector<int>arr;
      string curr = "";
        
        for(auto& x : data){
            if(x == '#'){
                arr.push_back(stoi(curr));
                curr = "";
            }
            
            else curr.push_back(x);
        }
        
        TreeNode* head = new TreeNode(arr[0]);
        auto insert = [&](int val , TreeNode* curr , auto&& insert)->void{
            if(!curr){
                return;
            }
            if(curr->val > val){
                if(curr->left)  insert(val,curr->left ,insert);
                else   curr->left = new TreeNode(val);
            }
            
            else{
               if(curr->right) insert(val,curr->right ,insert);
               else curr->right = new TreeNode(val);
            }
        };
        for(int i = 1;i<arr.size();i++)    insert(arr[i],head , insert);
        return head;
        
    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;