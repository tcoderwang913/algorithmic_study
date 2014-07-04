/**
Sort a linked list in O(n log n) time using constant space complexity.

[Analysis]
We use merge sort algorithms, which does sorting in-place with O(nlogn) time
1. FrontBackSplit
2. Merge first half
3. Merge second half
4. Merge two sorted lists
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
    void frontBackSplit(ListNode* head, ListNode*& first, ListNode*& second) {
       
        if (head == NULL || head->next == NULL) {
		    first = head;
		    second = NULL;
	    }
	    else {
	    	//Should be very familiar with this two pointer idiom to do
	    	//front back split
		    ListNode* slow = head;
		    ListNode* fast = head->next;
		
		    while (fast != NULL) {
			    fast = fast->next;
			    if (fast != NULL) {
				    slow = slow->next;
				    fast = fast->next;
			    }
		    }
		    first = head;
		    second = slow->next;
		    slow->next = NULL;
	    }
    }
    
    ListNode* merge(ListNode*& l1, ListNode*& l2) {
        ListNode dummy(0);
	    ListNode* curr = &dummy;
	
	    while (l1 && l2) {
		    int val = -1;
		    if (l1->val <= l2->val) {
			    val = l1->val;
			    l1 =l1->next;
		    }
		    else {
			    val = l2->val;
			    l2 = l2->next;
		    }
		
		    curr->next = new ListNode(val);
		    curr = curr->next;
	    }
	
	    while (l1) {
		    curr->next = new ListNode(l1->val);
		    l1 = l1->next;
		    curr = curr->next;
	    }
	
	    while (l2) {
		    curr->next = new ListNode(l2->val);
		    l2 = l2->next;
		    curr = curr->next;
	    }
	
	    return dummy.next;
    }
    
    
    void mergeSort(ListNode* &head) {
    	//Note that here we need to use a local variable since we are doing recursion
    	//more reason?
        ListNode* curr = head;
	    //list is null or has only 1 node, return 
	    if (curr == NULL || curr->next == NULL) return ;
	
	    ListNode* first ;
	    ListNode* second ;
	    frontBackSplit(head, first, second);
	
	    mergeSort(first);
	    mergeSort(second);
	
	    ListNode* res = merge(first, second);
	    head = res;
    }
    
    ListNode *sortList(ListNode *head) {
        mergeSort(head);
        return head;
    }
};