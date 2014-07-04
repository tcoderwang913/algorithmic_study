/**
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

/**
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || k ==0) return head; 
        //k ==0 means there is not need to rotate, return the original list
	
	    ListNode* p =head;
	    int len = 1;
	    while (p->next !=NULL)
	    {
		    p = p->next;
		    len ++;
	    }
	
	    k = len - k%len; 
	    //we need to consider the case that k might be larger than the lenght of the list
	    p->next = head; 
	    // connect the end node to the head
	    int step = 0;
	    while (step < k) {
		    p = p->next;
		    step ++;
	    }
	
	    head = p->next; // this is the new head
	    p->next = NULL; //new end of list
	
	    return head;
    }
};
