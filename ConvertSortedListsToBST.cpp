/**
Given a singly linked list where elements are sorted in ascending order, 
convert it to a height balanced BST.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    int getLengthOfList(ListNode* head) {
		ListNode* curr = head;
		int len = 0;
		while (curr) {
			++len;
			curr = curr->next;
		}
		
		return len;
	}
	
	//note that here we need to pass list head by REFERENCE
	TreeNode* buildTree(ListNode* &head, int start, int end) {
		if (start > end) return NULL;
		int mid = start + (end-start)/2;
		TreeNode* left = buildTree(head, start, mid -1);
		TreeNode* root = new TreeNode(head->val);
		root->left = left;
		head = head->next;
		TreeNode* right = buildTree(head, mid +1 , end);
		root->right = right;
		return root;
	}
	
    TreeNode *sortedListToBST(ListNode *head) {
    	int len = getLengthOfList(head);
    	return buildTree(head, 0, len-1);
    }
};