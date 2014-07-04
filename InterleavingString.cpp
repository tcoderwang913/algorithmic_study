/**
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

[Analysis]
Classical dp, consider 5 cases
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
    	if (s3.size() != m +n) return false;
    	
    	vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
    	for (int i = 0; i <=m ;++i) {
    		for (int j = 0; j <=n; ++j) {
    			if (i==0 && j ==0) dp[i][j] = true;
    			else if (i == 0 && s2[j-1] == s3[j-1]) dp[i][j] = dp[i][j-1];
    			else if (j == 0 && s1[i-1] == s3[i-1]) dp[i][j] = dp[i-1][j];
    			else if (s1[i-1] == s3[i+j-1] && s2[j-1] != s3[i+j-1]) {
    				dp[i][j] = dp[i-1][j];
    			}
    			else if (s2[j-1] == s3[i+j-1] && s1[i-1] != s3[i+j-1]){
    				dp[i][j] = dp[i][j-1];
    			}else if (s1[i-1] == s3[i+j-1] && s2[j-1] == s3[i+j-1]){
    				dp[i][j] = dp[i-1][j] || dp[i][j-1];
    			}
    		}
    	}
    	return dp[m][n];
    }
};