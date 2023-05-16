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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       
        ListNode* prv = NULL ,* ans = head;
        
        while(head){
            ListNode* tmp = head;
            head=  head->next;
            if(!head) break;
            
            if(!prv){
                ans = head;
                tmp->next = head->next;
                head->next = tmp;
            }
            
            else{
                prv->next = head;
                tmp->next = head->next;
                head->next = tmp;
            }
            
            head = tmp->next;
            prv = tmp;
        }
        
        return ans;
    }
};