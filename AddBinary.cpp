/**
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100"
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        int K = std::max(m,n);
        string res(K,' ');
        int i = m-1, j = n -1;
        int k = K-1;
        int carry = 0;
        while (i >=0 || j >=0) {
            int op1 = (i >=0)? a[i--] - '0': 0;
            int op2 = (j >=0)? b[j--] - '0': 0;
            res[k--] = (op1 + op2 + carry)%2 + '0';
            carry = (op1 + op2 + carry)/2;
        }
        
        if (carry >0) {
            res.insert(res.begin(), '1');
        }
        return res;
    }
};