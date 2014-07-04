/**
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid 
(marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n));
        dp[0][0] = 1;
        //init first row
        for (int i = 1; i < n; ++i) dp[0][i] = 1;
        //init first column
        for (int i = 1; i <m; ++i) dp[i][0] = 1;
        
        for (int i =1; i < m; ++ i) {
            for (int j = 1; j <n; ++j) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        
        return dp[m-1][n-1];
    }
};