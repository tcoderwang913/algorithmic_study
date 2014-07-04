/**
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, 
where n is the total number of rows in the triangle.

[Analysis]
一维DP。逐行扫描，每一个位置能取得的最小sum，是该元素上面两个能取得的最小sum中最小的那一个sum加上自己的值。
只需要开一个数组重复利用就行了。

实现的时候，有些繁琐的地方，这个题比较好从下往上扫描。如果从上往下，其中minV的初始值问题就很头疼。
*/

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int rows = triangle.size();
        if (rows ==0) return rows;
        vector<int> minSum(triangle[rows-1].size());
        
        for (int i = rows -1; i >=0; --i) {
            int cols = triangle[i].size();
            for (int j = 0; j < cols; ++j) {
                if (i == rows -1) {
                    minSum[j] = triangle[rows-1][j];
                    continue;
                }
                //Go through the given example matrix, you will understand that
                //this actually computes the minimum path bottom-up
                minSum[j] = std::min(minSum[j], minSum[j+1]) + triangle[i][j];
            }
        }
        return minSum[0];
    }
};