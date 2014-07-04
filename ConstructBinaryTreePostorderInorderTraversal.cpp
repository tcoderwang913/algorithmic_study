/**
Given inorder and postorder traversal of a tree, construct the binary tree.

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
     TreeNode* constructTree(vector<int> &inorder, vector<int> &postorder, 
     						int inOrderStart, int inOrderEnd,
                            int postOrderEnd)
    {
        if (inOrderStart > inOrderEnd) return NULL;
        TreeNode* res =  new TreeNode(postorder[postOrderEnd]);
        int mid = -1;
        for (int i = inOrderStart; i <= inOrderEnd; ++i) {
            if (inorder[i] == res->val)
            {
                mid = i;
                break;
            }
        }
        res->left = constructTree(inorder, postorder, inOrderStart, mid-1, 
        							postOrderEnd-1 - inOrderEnd +mid);
        res->right = constructTree(inorder, postorder, mid+1, inOrderEnd, postOrderEnd-1);
        return res;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.empty()) return NULL;
        return constructTree(inorder, postorder,0, inorder.size()-1, postorder.size()-1);
    }
};