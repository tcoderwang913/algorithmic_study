/**
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int inOrderStart, 
    					int inOrderEnd, int preOrderStart) {
        if (inOrderStart > inOrderEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preOrderStart]);
        int mid = -1;
        for (int i =inOrderStart; i <= inOrderEnd; ++i) {
            if (inorder[i] == preorder[preOrderStart]) {
                mid = i;
                break;
            }
        }
        root->left = construct(preorder, inorder, inOrderStart, mid-1, preOrderStart +1 );
        root->right = construct(preorder,inorder, mid +1, inOrderEnd, 
        					preOrderStart + 1 + mid - inOrderStart);
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) return NULL;
        
        return construct(preorder, inorder, 0, inorder.size() -1, 0);
    }
};