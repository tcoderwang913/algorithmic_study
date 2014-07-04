/**
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which 
the depth of the two subtrees of every node never differ by more than 1.
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
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        return std::max(1+ getHeight(root->left), 1+ getHeight(root->right));
    }
    
    bool isBalancedUtil(TreeNode* root) {
        if (!root) return true;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
       
        if (abs(left-right) <=1 && isBalancedUtil(root->left) && isBalancedUtil(root->right)) 
            return true;
        return false;
    }
    
    bool isBalanced(TreeNode *root) {
        return isBalancedUtil(root);
    }
};