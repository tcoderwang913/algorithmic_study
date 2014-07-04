/**
Given a linked list and a value x, partition it such that all nodes less than x 
come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x) {
        if (!head) return head;
        
        ListNode* curr = head;
        ListNode dummyLeft(0);
        ListNode dummyRight(0);
        ListNode* pLeft = &dummyLeft;
        ListNode* pRight = &dummyRight;
        while (curr) {
            if (curr->val <x) {
                pLeft->next = curr;
                pLeft = pLeft->next;
            }
            else {
                pRight->next = curr;
                pRight = pRight->next;
            }
            curr = curr->next;
        }
        pLeft->next = dummyRight.next;
        pRight->next = NULL;
        return dummyLeft.next;
    }
};