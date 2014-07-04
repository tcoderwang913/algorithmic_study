/**
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.size() ==0) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int> > dp(m, vector<int>(n));
        if (obstacleGrid[0][0] ==1) return 0;
        
        dp[0][0] = 1;
        
        //init first row
        for (int i = 1;i < n; ++i) {
            dp[0][i] = (obstacleGrid[0][i] ==1)? 0: dp[0][i-1];
        }
        
        //init first col
        for (int i = 1; i < m; ++i) {
            dp[i][0] = (obstacleGrid[i][0] ==1)? 0: dp[i-1][0];
        }
        
        for (int i =1; i < m; ++i) {
            for (int j =1; j < n; ++j) {
                dp[i][j] = (obstacleGrid[i][j] ==1) ?0 : (dp[i-1][j] + dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};