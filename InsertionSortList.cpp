/**
Sort a linked list using insertion sort.
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
	//The key is to understand is sorted insert algorithm
    void insert(ListNode* head, ListNode* tail, ListNode* node) {
        ListNode* curr = head;
        while (curr->next->val < node->val) {
            curr = curr->next;
        }
        tail->next = node->next;
        node->next = curr->next;
        curr->next = node;
    }
    
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(INT_MIN);
        
        dummy.next = head;
        ListNode* curr = &dummy;
        while (curr->next) {
            if (curr->next->val >= curr->val) {
                curr = curr->next;
            }
            else {
                insert(&dummy, curr, curr->next);
            }
        }
        return dummy.next;
    }
};