/**
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

[Analysis]
The idea is to use two stacks.
One stack store the sequence of pre-order sequence
any time when a node is poped from the pre-order stack
push it into the post-order stack

the last step is to pop every element from the post-order stack and put them into 
result set
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);

        // Run while first stack is not empty
        while (!s1.empty())
        {
            // Pop an item from s1 and push it to s2
            TreeNode* top = s1.top();
            s1.pop();
            s2.push(top);
 
            // Push left and right children of removed item to s1
            //note that for pre-order, first push right, then left
            //here we do the opposite
            if (top->left)
                s1.push(top->left);
            if (top->right)
                s1.push(top->right);
        }
 
        // Print all elements of second stack
        while (!s2.empty())
        {
            TreeNode* top = s2.top();
            res.push_back(top->val);
            s2.pop();
        }
    }
};