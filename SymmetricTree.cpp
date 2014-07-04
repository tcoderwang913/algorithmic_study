/**
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetricUtil(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if ((!left && right) || (left &&!right) ) return false;
        
        if (left->val == right->val) {
            return isSymmetricUtil(left->left, right->right) &&
                    isSymmetricUtil(left->right, right->left);
        }
        else {
            return false;
        }
    }
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isSymmetricUtil(root->left, root->right);
    }
};