/**
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/





class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0') return "0";
        int n1(num1.size()), n2(num2.size()), n(n1+n2);
        vector<int> r(n,0);
        string s(n,'0');
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++ j) {
                r[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
		
        for (int i =n -1; i >0; --i)
        {
            if (r[i] >9)
            {
                r[i-1] += r[i]/10;
            }
            s[i] += r[i] %10;
        }
        s[0] += r[0];
        return s[0] =='0'? string(s.begin() +1, s.end()):s;
    }
};


//solution online
class Solution {
public:
    string multiply(string num1, string num2) {
        int N = num1.size(), M = num2.size();
        string res(N+M, '0');
        for (int i = N - 1; i >= 0; --i)
        {
            int carry = 0;
            for (int j = M - 1; j >= 0; --j)
            {
                int sum = carry + (res[i+j+1] - '0') + 
                          (num1[i] - '0') * (num2[j] - '0');
                res[i+j+1] = sum % 10 + '0';
                carry = sum / 10;
            }
            res[i] += carry;
        }
        while (res.size() > 1 && res[0] == '0')
            res.erase(res.begin());
        return res;
    }
};
