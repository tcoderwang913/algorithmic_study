/**
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        
        stack<TreeNode*> S;
        TreeNode* curr = root;
        bool done = false; 
        
        while (!done) {
            if (curr) {
                S.push(curr);
                curr = curr->left;
            }
            else {
                if (!S.empty()) {
                    TreeNode* top = S.top();
                    res.push_back(top->val);
                    S.pop();
                    curr = top->right;
                }
                else {
                    done = true;
                }
            }
        }
        return res;
    }
};