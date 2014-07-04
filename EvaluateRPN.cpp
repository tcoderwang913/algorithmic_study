/**
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")  {
                st.push(atoi(tokens[i].c_str()));
                continue;
            }
            
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            
            if (tokens[i] == "+") st.push(op2 + op1);
            if (tokens[i] == "-") st.push(op2 - op1);
            if (tokens[i] == "*") st.push(op2 * op1);
            if (tokens[i] == "/") st.push(op2 /op1) ;//need to consider op1 = 0 case
        }
        return st.top();
    }
};