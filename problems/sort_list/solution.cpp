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
    int getListSize(ListNode* list) {
        int listSize = 1;
        while(list->next){
            listSize++;
            list = list->next;
        }
        return listSize;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        int size = getListSize(head);
        for(int p = 1; p < size; p*=2) {
            ListNode* curr = new ListNode(INT_MIN, head);
            while(curr && curr->next) {
                ListNode* l1 = curr->next;
                ListNode* l1End = curr;
                for(int i =0; i<p && l1End; i++ ) {
                    l1End=l1End->next;
                }
                if(!l1End || !l1End->next) break;
                ListNode* l2 = l1End->next;
                ListNode* l2End = l2;
                l1End->next = NULL;
                for(int i =1; i<p && l2End; i++) {
                    l2End=l2End->next;
                }
                ListNode* after = NULL;
                if(l2End){
                     after = l2End->next;
                     l2End->next = NULL;
                };
                vector<ListNode*> newListStartEnd = mergeTwoLists(l1,l2);
                if(curr->val == INT_MIN) head = newListStartEnd[0];
                curr->next = newListStartEnd[0];
                curr = newListStartEnd[1];
                curr->next = after;
            }
        }
        return head;
    }
    vector<ListNode*> mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* S = new ListNode();
        ListNode* nHead = S;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                S->next = l1;
                l1 = l1->next;
                S = S->next;
            } else {
                S->next = l2;
                l2=l2->next;
                S=S->next;
            }
        }
        while(l1) {
            S->next = l1;
            l1 = l1->next;
            S = S->next;
        }
        while(l2) {
           S->next = l2;
            l2=l2->next;
            S=S->next;
        }
        return {nHead->next, S};
    }
};