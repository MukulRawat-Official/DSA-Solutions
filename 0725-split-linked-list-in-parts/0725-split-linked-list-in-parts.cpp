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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int count = 0;
        ListNode* tmp = head;
        while(tmp) {count++; tmp = tmp->next;}
        vector<ListNode*> arr;
        
        
        int cnt = k , tot = k;
        while(cnt){
            
            if(cnt == 1 || !head) {arr.push_back(head); break;}
            else{
                int r = count / cnt + (count % cnt != 0);
                tmp = head;
                count -= r;
                
                
                while(r > 1){
                    tmp = tmp ->next;
                    r--;
                }
             
                arr.push_back(head);
                head = tmp->next;
                tmp->next = NULL;
            }
            cnt--;
            
        }
        while(arr.size() < tot) arr.push_back(NULL);
        
        return arr;
        
    }
};