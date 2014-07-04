/**
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum 
equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
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
   void dfs(vector<vector<int> >& ret, vector<int> path, TreeNode* root, int sum, int currSum){
		//note that these two statements have to be before the return block check
		path.push_back(root->val);
		currSum += root->val;
		if (currSum == sum && !root->left && !root->right) {
			ret.push_back(path);
			return;
		}
		
		if (root->left) {
			dfs(ret, path, root->left, sum, currSum);
		}
		if (root->right) {
			dfs(ret, path, root->right, sum, currSum);
		}
		path.pop_back();
		currSum -= root->val;
	}
	
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ret;
        if (!root) return ret;
        vector<int> path;
        dfs(ret, path, root, sum, 0);
        return ret;
    }
};