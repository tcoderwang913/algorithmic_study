/**
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
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
        queue<pair<TreeLinkNode*, int> > que;
        if (root==NULL) {return;}
        que.push(pair<TreeLinkNode*, int>(root,1));
         
        while (!que.empty()){
            pair<TreeLinkNode*, int>p =que.front();
            que.pop();
            if (p.first->left!=NULL){
                que.push(pair<TreeLinkNode*, int>(p.first->left,p.second+1));
            }
            if (p.first->right!=NULL){
                que.push(pair<TreeLinkNode*, int>(p.first->right,p.second+1));
            }
             
            if (que.empty()){
                p.first->next = NULL;
                return;
            }
            if (p.second != que.front().second){
                p.first->next = NULL;
            }else{
                p.first->next = que.front().first;
            }
        } 
    }
};