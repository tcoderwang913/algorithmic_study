/**
Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ret;
        if (!root) return ret;
        
        vector<int> level;
        vector<TreeNode*> buf;
        buf.push_back(root);
        while (!buf.empty()) {
            level.clear();
            vector<TreeNode*> temp;
            for (int i = 0; i < buf.size(); ++i) {
                TreeNode* node = buf[i];
                level.push_back(node->val);
                if (node->left) temp.push_back(node->left);
                if (node->right) temp.push_back(node->right);
            }
            ret.push_back(level);
            buf = temp;
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};
