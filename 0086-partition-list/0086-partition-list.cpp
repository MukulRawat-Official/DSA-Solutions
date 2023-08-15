/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
typedef ListNode node;
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        node* less = new node(0) , *great = new node(0);
        node* lt = less , *gt = great;
        
        node* temp = head;
        
        
        while(temp)
        {
            if(temp->val<x)
            {
                lt->next = temp;
                temp = temp->next;
                lt = lt->next;
                lt->next = NULL;
            }
            
            else
            {
               gt->next = temp;
               temp = temp->next;
                gt = gt->next;
                gt->next = NULL;
            }
        }
        
        lt->next = great->next;
        return less->next;
    }
};