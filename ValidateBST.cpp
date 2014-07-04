/**
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
    bool isValidBSTUtil(TreeNode* root, int min, int max) {
        if (!root) return true;
        if (root->val <= min || root->val >= max) return false;
        return (isValidBSTUtil(root->left, min, root->val)  &&
            isValidBSTUtil(root->right, root->val, max));
    }
    
    bool isValidBST(TreeNode *root) {
        return isValidBSTUtil(root,INT_MIN, INT_MAX);
    }
};