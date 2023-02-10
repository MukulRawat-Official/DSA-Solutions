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
    ListNode* reverseList(ListNode* head) {
       
        auto rev = [&](ListNode* head,auto&& rev)->ListNode*{
            if(!head || !head->next) return head;
            ListNode* tmp = rev(head->next,rev);
            head->next->next = head;
            head->next = NULL;
            return tmp;
        };
        
        return rev(head,rev);
    }
};