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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        int id = 0;
        for(auto& x : lists){
            if(x){
            pair<int,int>tmp = {x->val , id};
            pq.push(tmp);
            }
            id++;
        }
        
        ListNode* head  , *tail;
        head = tail = NULL;
        while(pq.size()){
            pair<int,int>tmp = pq.top(); pq.pop();
            if(!head){
                head = lists[tmp.second];
                tail = lists[tmp.second];
            }
            
            else{
                tail->next = lists[tmp.second];
                tail = lists[tmp.second];
            }
            
            lists[tmp.second] = lists[tmp.second]->next;
            if(lists[tmp.second]) pq.push({lists[tmp.second]->val , tmp.second});
      } 
        if(tail)
        tail->next = NULL;
        return head;
    }
    };