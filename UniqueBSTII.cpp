/**
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode *> generateTrees(int n) {
      	if(n ==0) return *generate(1,0);  
	    return *generate(1, n);  
    }  


    vector<TreeNode *>* generate(int start, int end)  
    {  
	    vector<TreeNode *> *subTree = new vector<TreeNode*>();  
	    if(start>end)  
	    {  
		    subTree->push_back(NULL);  
		    return subTree;  
	    }  
	
	    for(int i =start; i<=end; i++)  
	    {  
		    vector<TreeNode*> *leftSubs = generate(start, i-1);  
		    vector<TreeNode*> *rightSubs = generate(i+1, end);  
		    for(int j = 0; j< leftSubs->size(); j++)  
		    {  
			    for(int k=0; k<rightSubs->size(); k++)  
			    {  
				    TreeNode *node = new TreeNode(i);  
				    node->left = (*leftSubs)[j];  
				    node->right = (*rightSubs)[k];  
				    subTree->push_back(node);  
			    }  
		    }  
	    }  
	    return subTree;  
    }     
};