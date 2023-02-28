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
    // 1 2 NULL NULL 3 4 NULL NULL 5 NULL NULL
    // Encodes a tree to a single string.
   
    string serialize(TreeNode* root) {
       if(!root)return "#"; 
       string left = serialize(root->left) + "/";
       string right = serialize(root->right);
       
       string curr = to_string(root->val) + "/" + left + right;
       return curr;
    }

    
    // Decodes your encoded data to tree.
    TreeNode* decode(string& data , int& idx){
        if(idx >= data.size()) return NULL;
        
        string hv = "";
        while(idx<data.size() && data[idx] != '/') hv.push_back(data[idx++]);
        if(hv == "#") return NULL;
        
        TreeNode* curr = new TreeNode(stoi(hv));
        
        idx++;
        curr->left = decode(data,idx); 
        idx++;
        curr->right = decode(data,idx);
        
        return curr;
    }
    TreeNode* deserialize(string data) {
        data.push_back('/');   
        int idx = 0;
        return decode(data,idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));