/**
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node 
down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 1));
        while (! q.empty()) {
            pair<TreeNode*, int> top = q.front();
            TreeNode* node = top.first;
            if (!node->left && !node->right) return top.second;
            q.pop();
            if (node->left) {
                q.push(make_pair(node->left, top.second +1));
            }
            if (node->right) {
                q.push(make_pair(node->right, top.second +1));
            }
        }
    }
};