/**
Rotate an image by 90 degree
i.e., rotate an n*n matrix by 90 degree clockwise

example
1 2 3               7   4  1
4 5 6     --------> 8   5  2
7 8 9               9   6  3

[Analysis]
first do transpose, then reverse all the rows
*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if ( 0 == matrix.size()) return ; //do nothing for empty matrix
		
		//get the transpose of the matrix
		//note only j <=i
		for (int i = 0; i < matrix.size(); ++i ) {
			for (int j = 0; j <= i; ++j ) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		
		for (int i = 0; i < matrix.size(); ++i ) {
			std::reverse(matrix[i].begin(), matrix[i].end());
		}
    }
};