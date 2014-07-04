/**
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/


//This question needs some time to understand
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head){
            return NULL;
        }
        ListNode* p=new ListNode(0);
        p->next=head;
        head = p;
        ListNode* q=p;
        while (true){
            int i=0;
            while (q && i<k){
                q=q->next;
                i++;
            }
            if (!q){
                return head->next;
            }
            else{
                while (p->next!=q){
                    ListNode* d = p->next;
                    ListNode* l = q->next;
                    p->next=p->next->next;
                    q->next=d;
                    d->next=l;
                }
                for(int j=0;j<k;j++){
                    p=p->next;
                }
                q=p;
            }
        }
        return head->next;
    }
};
