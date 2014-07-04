/**
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <i; ++j) {
                if (s[j] == s[i] && (i-j <2 || dp[j+1][i-1])) {
                    dp[j][i] = true;
                }
            }
            dp[i][i] = true;
        }
        
        vector<int> res(n,0);
        for (int i =0; i < n; ++i) {
            int minCut = n;
            if (dp[0][i]) {
                res[i] = 0;
            }
            else {
                for (int j = 0; j< i; ++j) {
                    if (dp[j+1][i] && minCut > res[j] +1) {
                        minCut = res[j] +1;
                    }
                }
                res[i] = minCut;
            }
        }
        return res[n-1];
    }
};