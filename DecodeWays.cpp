/**
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

[Analysis]
思路类似于climb stairs但是增加了很多限制：
1. 如果s[i] == '0', 那么ways[i] = 0； 如果s[i]有有效字符对应则ways[i] = ways[i-1];
2. 如果s[i-2,i-1] 可以组成有效decode,那么ways[i] += ways[i-2].  
有效的decode就是这两位数要么以1开始，要么以2开始,如果以2开始，那么第二个数必须<=6
*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        vector<int> ways(n+1,0);
        ways[0] = 1;
        for(int i = 1; i <= n; i++ ) {
            if (s[i-1] != '0')
                ways[i] = ways[i-1];        
            if (i >= 2 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <='6')))
                //need to make sure i>=2    //don't forget the pair of parentheses here
                ways[i] += ways[i-2];
        }

        return ways[n];
    }
};