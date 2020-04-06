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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) {
            return NULL;
        }
        
        ListNode* aPtr = headA;
        ListNode* bPtr = headB;
        
        ListNode* endA = NULL;
        ListNode* endB = NULL;
        
        while(aPtr != bPtr) {
            if(endA != NULL && endB != NULL && endA != endB) {
                return NULL;
            }
            if(aPtr->next == NULL) {
                endA=aPtr;
                aPtr = headB;
            } else {
                aPtr = aPtr->next;
            }
            if(bPtr->next == NULL) {
                endB=bPtr;
                bPtr = headA;
            } else {
                bPtr = bPtr->next;
            }
        }
        
        return aPtr;
        
    }
};