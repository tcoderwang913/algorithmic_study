/**
Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

[Analysis]
Add a dummy node, the reason is that we may have duplicates starting from head

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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
    	
    	ListNode * pre = new ListNode(0);
    	pre->next = head;
    	head = pre;
    	
    	ListNode* p = head;
    	while (p->next) {
    		ListNode* p2 = p->next;
    		while (p2->next && p2->val == p2->next->val) {
    			p2 = p2->next;
    		}
    		
    		if (p2 !=  p->next) {
    			p->next = p2->next;
    		}
    		else {
    			p = p->next;
    		}
    	} 
    	
    	return head->next;
    }
};