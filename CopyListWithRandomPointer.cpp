/**
A linked list is given such that each node contains an additional random pointer 
which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        
        map<RandomListNode*, RandomListNode*> mp;
        mp.clear();
        RandomListNode* res = new RandomListNode(0);
        RandomListNode* p = head;
        RandomListNode* q = res;
        
        while (p) {
            RandomListNode* tmp = new RandomListNode(p->label);
            q->next = tmp;
            mp[p] = tmp;
            p = p->next;
            q = q->next;
        }
        
        p = head;
        q = res->next;
        while (p) {
            if( p->random == NULL) {
                q->random = NULL;
            }
            else {
                q->random = mp[p->random];
            }
            p = p->next;
            q = q->next;
        }
        
        return res->next;
    }
};


//Another solution
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        for (RandomListNode *cur = head; cur; cur = cur->next->next) {
            RandomListNode *newNode = new RandomListNode(cur->label);
            newNode->next = cur->next;
            cur->next = newNode;
        }
        
        for (RandomListNode *cur = head; cur; cur = cur->next->next)
            if (cur->random)
                cur->next->random = cur->random->next;
        
        RandomListNode dummy(0), *curNew = &dummy;
        for (RandomListNode *cur = head; cur; cur = cur->next) {
            curNew->next = cur->next;
            curNew = curNew->next;
            cur->next = cur->next->next;
        }
        return dummy.next;
        
    }
};