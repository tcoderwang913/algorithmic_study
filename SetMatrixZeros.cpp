/**
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.size() ==0) return ;
        if (matrix[0].size() ==0) return ;
        
        bool setFirstRow = false;
        bool setFirstColumn = false;
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                setFirstColumn = true;
                break;
            }
        }
        
        for (int i = 0; i < matrix[0].size(); ++i) {
            if (matrix[0][i] == 0) {
                setFirstRow = true;
                break;
            }
        }
        
        for (int i =1; i< matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] ==0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j =1; j < matrix[0].size(); ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] ==0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        //set first row and column
        if (setFirstRow) {
            for (int i = 0; i < matrix[0].size(); ++i) matrix[0][i] = 0;
        }
        if (setFirstColumn) {
            for (int i = 0; i < matrix.size(); ++i) matrix[i][0] = 0;
        }
    }
};