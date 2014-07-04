/**
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
	//clear dfs use pathsum to record sum in current path
	//add path sum to total sum
    void dfs(TreeNode* root, int& sum, int pathSum) {
        if (!root) return ;
        pathSum = pathSum * 10 + root->val;
        if (!root->left && !root->right) {
            sum += pathSum;
            return ;
        }
        
        dfs(root->left, sum, pathSum);
        dfs(root->right, sum, pathSum);
    }
    
    int sumNumbers(TreeNode *root) {
        int sum = 0, pathSum = 0;
        dfs(root, sum,pathSum);
        return sum;
    }
};