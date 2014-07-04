/**
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no 
next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, 
and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return ;
        root->next = NULL;
        connectRecur(root);
    }
    
    /* Set next of all descendents of p.
        Assumption:  p is a compete binary tree */
    void connectRecur(TreeLinkNode* p)
    {
        // Base case
        if (!p)
            return;
 
        // Set the next pointer for p's left child
        if (p->left)
            p->left->next = p->right;
 
        // Set the next pointer for p's right child
        // p->next will be NULL if p is the right most child at its level
        if (p->right)
            p->right->next = (p->next)? p->next->left: NULL;
 
        // Set nextRight for other nodes in pre order fashion
        connectRecur(p->left);
        connectRecur(p->right);
    }
};
    
    