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
    ListNode* rev(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* tmp = rev(head->next);
        tmp->next = head;
        head->next = NULL;
        return head;  
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head , *fast = head , *tail;
        
        while(fast){
            tail = fast->next;
            fast = fast->next->next;
            slow = slow->next;
        }
        
         slow = rev(slow);
        
        int ans = 0;
        while(tail){
            ans = max(ans , tail->val + head->val);
            tail = tail->next;
            head = head->next;
        }
        
        return ans;
    }
};