/**
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode* dummy = new ListNode(0);  
	    dummy->next = head;  
   
	    // first if the first position, begin is the node before first.  
	    ListNode* pre = dummy;
	    ListNode* cur=head;  
	    int pos = 1;  
   
	    // find the first  
	    while (pos < m && cur != NULL) {  
		    pre = cur;  
		    cur = cur->next;  
		    ++pos;  
	    }  
   
	    // reverse the list  
	    while (pos < n && cur != NULL) {  
		    ListNode* nt = cur->next->next;  
		    cur->next->next = pre->next;  
		    pre->next = cur->next;  
		    cur->next = nt;  
		    ++pos;  
	    }
   
	    return dummy->next; 
    }
};