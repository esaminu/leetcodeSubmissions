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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next || m==n){
            return head;
        }
        
        ListNode* tail;
        ListNode* subStart = head;
        
        for(int k = 1; k<m; k++) {
            tail = subStart;
            subStart = subStart->next;
        }
        
        if(m > 1) {
            tail->next = reverse(subStart, n - m)[1];
            return head;
        }
        return reverse(subStart, n - m)[1];
        
    }
    
    vector<ListNode*> reverse(ListNode* head, int moves) {
        static ListNode* headPtr;
        if(!moves) {
            headPtr = head;
            return {head, headPtr};
        }
        ListNode* prev = reverse(head->next, moves - 1)[0];
        ListNode* q = head->next;
        head->next = prev->next;
        q->next = head;
        
        return {head, headPtr};
    }
};