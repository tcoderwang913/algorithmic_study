/**
Given a binary tree, return the zigzag level order traversal of its nodes' values.
 (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        if (!root) return ret;
        vector<int> level;
        
        stack<TreeNode*> currLevel;
        stack<TreeNode*> nextLevel;
        bool leftToRight = false;
        currLevel.push(root);
        while (!currLevel.empty()) {
            TreeNode* node = currLevel.top();
            currLevel.pop();
            level.push_back(node->val);
            
            if (leftToRight) {
                if (node->right) nextLevel.push(node->right);
                if (node->left) nextLevel.push(node->left);
            }
            else {
                if (node->left) nextLevel.push(node->left);
                if (node->right) nextLevel.push(node->right);
            }
            
            if (currLevel.empty()) {
                currLevel = nextLevel;
                ret.push_back(level);
                level.clear();
                leftToRight = !leftToRight;
                
                while (!nextLevel.empty()) {
                    nextLevel.pop();
                }
            }
            
        }
        return ret;
    }
};