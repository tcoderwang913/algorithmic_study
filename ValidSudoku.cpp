/**
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        map<char, bool> row;
        map<char, bool> col;
        map<char, bool> block;

        for (int i=0;i<9;i++){
            col.clear();
            row.clear();
            for (int j=0;j<9;j++){
                if (board[i][j]!='.'){
                    if (col[board[i][j]]){
                        return false;
                    }else{
                        col[board[i][j]]=true;
                    } 
                }
                if (board[j][i]!='.'){
                    if (row[board[j][i]]){
                        return false;
                    }else{
                        row[board[j][i]]=true;
                    } 
                }
            }
        }

        for (int ii=0;ii<9;ii=ii+3){
            for (int jj=0;jj<9;jj=jj+3){
                block.clear();
                for (int i=ii;i<ii+3;i++){
                    for (int j=jj;j<jj+3;j++){
                        if (board[i][j]!='.'){
                            if (block[board[i][j]]){
                                return false;
                            }else{
                                block[board[i][j]]=true;
                            } 
                        }
                    }
                } 
            }
        }

        return true;
    }
};