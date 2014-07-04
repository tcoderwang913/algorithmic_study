/**
Given a binary tree, return the level order traversal of its nodes' values.
 (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;
    	if (!root) return ret;
    	
    	vector<TreeNode*> buf;
    	vector<int> level;
    	buf.push_back(root);
    	while(!buf.empty()){
    		level.clear();
    		vector<TreeNode*> temp;
    		for (int i =0; i < buf.size(); ++i) {
    			TreeNode* node = buf[i];
    			level.push_back(node->val);
    			if (node->left) temp.push_back(node->left);
    			if (node->right) temp.push_back(node->right);
    		}
    		ret.push_back(level);
    		buf = temp;
    	}
    	return ret;
    }
};