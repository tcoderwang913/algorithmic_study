/**
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode* cbst(vector<int>& num, int start, int end) {
   		if (start > end) return NULL;
   		
   		int mid = start + (end - start) /2;
   		TreeNode* root = new TreeNode(num[mid]);
   		root->left = cbst(num, start, mid-1);
   		root->right = cbst(num, mid +1, end);
   		return root;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.empty()) return NULL;
    	return cbst(num, 0, num.size()-1);
    }
};