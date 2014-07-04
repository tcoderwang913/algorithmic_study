/**
Longest palindrome substring

[Analysis]
Denote dp[i][j] as whether the substring s[i..j] is a palindrome.
what makes s[i..j] a palindrome?
Case 1. if i ==j, we have a single characters, certainly it is 
a palindrome;
Case 2. if s[i] == s[j]  
		now if j ==i +1, we have a palindrome
		    otherwise j > i +1, we must make  sure dp[i+1][j-1] is also a palindrome

Based on this analysis, we can use a table to find out which pair of (i,j) gives 
the longest palindrome.
*/


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        int maxLen = 0, start = 0,end = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <i; ++j) {
                dp[i][j] = (s[i] == s[j] && (i -j <=1 || dp[i-1][j+1] ));
                if (dp[i][j] && maxLen < i -j +1) {
                    start = j;
                    end  = i;
                    maxLen = i -j +1;
                }
            }
            dp[i][i] = true;
        }
        return s.substr(start, end - start +1);
        
        
    }
};