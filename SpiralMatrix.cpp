/**
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int rows = matrix.size();
        if (rows ==0) return vector<int>();
        int cols = matrix[0].size();
        
        int topRow = 0, bottomRow = rows -1, leftCol = 0, rightCol = cols -1;
        vector<int> res;
        while (topRow <= bottomRow && leftCol <= rightCol) {
            //print top row
            for (int j = leftCol; j <= rightCol; ++j) {
                res.push_back(matrix[topRow][j]);
            }
            topRow ++;
            
            //print right column
            for (int i = topRow; i <= bottomRow; ++ i ) {
                res.push_back(matrix[i][rightCol]);
            }
            rightCol --;
            
            if (topRow <= bottomRow) {
                for (int j = rightCol; j >= leftCol; --j) {
                    res.push_back(matrix[bottomRow][j]);
                }
                bottomRow --;
            }
            
            if (leftCol <= rightCol) {
                for (int i = bottomRow; i >= topRow; --i) {
                    res.push_back(matrix[i][leftCol]);
                }
                leftCol ++;
            }
        }
        return res;
    }
};