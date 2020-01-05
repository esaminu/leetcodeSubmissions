/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carried = 0;
        ListNode currl1 = l1;
        ListNode currl2 = l2;
        
        ListNode total = null;
        ListNode currTotalNode = total;
        while(currl1.next != null || currl2.next != null) {
            int currSum = currl1.val + currl2.val + carried;
            if(currSum >= 10) {
                carried = 1;
            } else {
                carried = 0;
            }
            currSum = currSum % 10;
            if(total != null) {
                currTotalNode.next = new ListNode(currSum);
                if(currl1.next != null) {
                    currl1 = currl1.next;
                } else {
                   currl1 = new ListNode(0); 
                }
                
                if(currl2.next != null) {
                    currl2 = currl2.next;
                } else {
                   currl2 = new ListNode(0); 
                }
                currTotalNode = currTotalNode.next;
            } else {
                total = new ListNode(currSum);
                currTotalNode = total;
                if(currl1.next != null) {
                    currl1 = currl1.next;
                } else {
                   currl1 = new ListNode(0); 
                }
                
                if(currl2.next != null) {
                    currl2 = currl2.next;
                } else {
                   currl2 = new ListNode(0); 
                }
            }
            
        }
        if(currTotalNode != null) {
             int sum = currl1.val + currl2.val + carried;
            ListNode remainingTotal = null;
            if(sum >= 10) {
                remainingTotal = new ListNode(sum % 10);
                remainingTotal.next = new ListNode(1);
            } else {
                remainingTotal = new ListNode(sum);
            }
            currTotalNode.next = remainingTotal;
        }
        
        if(total != null) {
            return total;
        }
        int sum = currl1.val + currl2.val;
        if(sum >= 10) {
            total = new ListNode(sum % 10);
            total.next = new ListNode(1);
        } else {
            total = new ListNode(currl1.val + currl2.val);
        }
        
        return total;
    }
}