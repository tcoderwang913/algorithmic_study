/**
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. 
Could you devise a constant space solution?
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     void recoverTreeHelper(TreeNode *root, TreeNode* &pre, TreeNode* &fst, TreeNode* &snd){
        if(!root) return;
        recoverTreeHelper(root->left, pre, fst, snd);
        if(pre!=NULL && pre->val>root->val){
            if(fst==NULL){
                fst=pre;
                snd=root;
            }
            else
                snd=root;
        }
        pre=root;
        recoverTreeHelper(root->right, pre, fst, snd);
    }
    void recoverTree(TreeNode *root) {
        TreeNode *fst=NULL;
        TreeNode *snd=NULL;
        TreeNode *pre=NULL;
        recoverTreeHelper(root, pre, fst, snd);
        if(fst==NULL)
            return;
        int tmp = fst->val;
        fst->val = snd->val;
        snd->val = tmp;
    }
};