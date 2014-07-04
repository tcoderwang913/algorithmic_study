/**
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n));
        
        int topRow = 0, bottomRow = n -1, leftCol = 0, rightCol = n -1;
        int num = 1;
        while (true) {
            for (int j = leftCol; j <= rightCol; ++j) {
                matrix[topRow][j] = num ++;
            }
            topRow ++;
            if (topRow > bottomRow) break;
            
            for (int i = topRow; i <= bottomRow; ++i) {
                matrix[i][rightCol] = num ++;
            }
            rightCol --;
            if (rightCol < leftCol) break;
            
            for (int j = rightCol; j >= leftCol; --j) {
                matrix[bottomRow][j] = num ++;
            }
            bottomRow --;
            if (bottomRow < topRow) break;
            
            for (int i = bottomRow; i >= topRow; --i) {
                matrix[i][leftCol] = num ++;
            }
            leftCol ++;
            if (leftCol > rightCol) break;
        }
        return matrix;
    }
};