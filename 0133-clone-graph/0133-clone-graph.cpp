/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
typedef Node node;
class Solution {
public:
  map<node* , node*>m;
    Node* cloneGraph(Node* root) {
        if(!root) return root;
        
        node* t = new node(root->val);
        m[root] = t;
        for(auto& x : root->neighbors)
        {
            if(m.count(x))
                t->neighbors.push_back(m[x]);
            else
            t->neighbors.push_back(cloneGraph(x));
        }
        return t;
    }
};