/**
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int rows = matrix.size();
        if (0 ==rows) return false;
        int cols = matrix[0].size();
        
        int low = 0, high = rows*cols -1;
        
        while (low <= high) {
            int mid = low + (high -low)/2;
            int rowIndex = mid/cols;
            int colIndex = mid%cols;
            if (matrix[rowIndex][colIndex] == target) return true;
            else if (matrix[rowIndex][colIndex] < target) low = mid +1;
            else high = mid -1;
        }
        return false;
    }
};

