/**
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > pascal;
        if (numRows ==0) return pascal;
        
        vector<int> row;
        row.push_back(1);
        pascal.push_back(row);
        //no equal sign at numRows and i+1
        for (int i = 1; i < numRows; ++i) {
            vector<int> currRow(i+1);
            for (int j = 0; j < i +1; ++ j) {
                if (j==0 || i ==j) {
                    currRow[j] = 1;
                }
                else {
                    currRow[j] = pascal[i-1][j-1] + pascal[i-1][j];
                }
            }
            pascal.push_back(currRow);
        }
        
        return pascal;
    }
};