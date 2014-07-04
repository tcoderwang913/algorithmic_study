/**
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode* res = &dummy;
        
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                res->next = p1;
                p1 = p1->next;
            }
            else {
                res->next = p2;
                p2 = p2->next;
            }
            res = res->next;
        }
        
        while (p1) {
            res->next = p1;
            p1 = p1->next;
            res = res->next;
        }
        
        while (p2) {
            res->next = p2;
            p2 = p2->next;
            res = res->next;
        }
        
        return dummy.next;
    }
};