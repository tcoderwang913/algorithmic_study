/**
Given n pairs of parentheses, write a function to generate all 
combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/


class Solution{
public:
	void generateUtil(vector<string>& ret, string paren, int left, int right) {
		if (left ==0 && right ==0) {
			ret.push_back(paren);
			return ;
		}
		
		if (left >0 ) {
			generateUtil(ret, paren + "(", left -1, right);
		}
		
		if (right >left) {
			generateUtil(ret, paren + ")", left, right -1);
		}
	}
	
	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		string paren = "";
		generateUtil(ret, paren, n, n);
		return ret;
	}
};