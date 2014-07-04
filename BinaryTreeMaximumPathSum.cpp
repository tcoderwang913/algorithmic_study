/**
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

[IDEA]
A good idea found from the internet is:

1. Set one variable to store the max sum.
2. Scan every node in the tree.
3. For each node, compute the max sum of left sub tree and max sum of the right sub tree, 
mention that here the max sum is from the path that goes end at the left child, 
and start from any one of the node below the left child. (recursively)
4. Compare the max sum to the (left+right+current-val), be careful with the "-", 
if left<0 don't add left, same for the right. And update the max sum.


For each node(sub tree), there are two status, one is the path ends at this node, 
the other is the path goes through this node. 
In the first case, the path sum is current-val+max(left_s,right_s). and the sum here 
can be used for the parent of this node. 
In the second case, just compare the sum current-val+ left_s + right_s with the 
current max_sum, and update the max_sum.
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
    int maxPathSum(TreeNode *root) {
        int res = INT_MIN;
        maxPathSumRe(root, res);
        return res;
    }

    int maxPathSumRe(TreeNode *node, int &res)
    {
        if (!node) return 0;
        int l = maxPathSumRe(node->left, res);
        int r = maxPathSumRe(node->right, res);
        int sum = max(node->val, max(l, r) + node->val);
        res = max(res, sum);
        res = max(res, l + r + node->val);
        return sum;
    }
};
