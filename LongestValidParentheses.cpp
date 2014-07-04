/**
Given a string containing just the characters '(' and ')', find the length of the 
longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", 
which has length = 4.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        int last = -1;
        stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                if (st.empty()) {
                    last = i;
                }
                else {
                    st.pop();
                    if (st.empty()) {
                        maxLen = std::max(maxLen, i - last);
                    }else {
                        maxLen = std::max(maxLen, i - st.top());
                    }
                }
            }
        }
        return maxLen;
    }
};