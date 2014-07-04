/**
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" 
cells are those horizontally or vertically neighboring. The same letter cell may 
not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
public:
    bool dfs(vector<vector<char> >&board, string word, vector<vector<bool> >& visited,
            int i, int j) {
        if (i <0 || i >= board.size() || j <0 || j > board[0].size()) return false;
        if (word.size() ==0) return true;
        if (board[i][j] != word[0]) return false;
        if (visited[i][j]) return false;
        
        string s = word.substr(1, word.size());
        visited[i][j] = true;
        if (dfs(board, s, visited, i+1, j) ||
            dfs(board, s, visited, i-1, j) ||
            dfs(board, s, visited, i, j+1) ||
            dfs(board, s, visited, i, j-1) )
        {
            return true;
        }
        else {
            visited[i][j] = false;
            return false;
        }
    }
    
    
    bool exist(vector<vector<char> > &board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool> > visited(rows, vector<bool>(cols, false));
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, word, visited, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};