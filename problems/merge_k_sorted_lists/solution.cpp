/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct PtrCurrent {
            bool operator<(const PtrCurrent& that) const {
              return current->val > (that.current)->val;
            }

            ListNode* current;
         };
        priority_queue<PtrCurrent> qu;
        
        for(int i = 0; i<lists.size(); i++) {
            if(lists[i]) {
                qu.push(PtrCurrent{lists[i]});
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        
        while(qu.size()) {
            auto [current] = qu.top();
            p->next = current;
            qu.pop();
            p=p->next;
            if(current->next) {
                qu.push(PtrCurrent{current->next});
            }
        }
        return dummy->next;
    }
};