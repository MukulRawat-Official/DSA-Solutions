/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        Node* itr = head;
        while(itr)
        {
            Node* copyNode = new Node(itr->val);
            copyNode->next = itr->next;
            itr->next = copyNode;
            itr = copyNode->next;
        }
        
        
        itr = head;
        
        Node* newHead = itr->next , *dummyNode = NULL;
    
    
        while(itr){
            dummyNode = itr->next;
            if(itr->random) dummyNode->random = itr->random->next;
            else dummyNode->random = NULL;
            itr = dummyNode->next;
        }
        
        itr = head;
        
        while(itr){
            dummyNode = itr->next;
            if(dummyNode->next){
               itr->next = dummyNode->next;
               dummyNode->next = itr->next->next;
            }    
            else
                itr->next = dummyNode->next = NULL;
            
            itr = itr->next;
        }
        
        
        return newHead;
    }
};