/**
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

算法如下：
1. 从四条边上的O元素开始BFS，所有相连的O都赋个新值，比如‘Y’
2. 扫描整个数组，所有现存的O元素全部置为X，所有Y元素置为O
*/

class Solution {
public:
    vector<int> xIndex;  
	vector<int> yIndex;  
	void solve(vector<vector<char>> &board) {  
		int row = board.size();  
		if(row == 0) return;  
		int col = board[0].size();
  
		xIndex.clear();  
		yIndex.clear();            
		for(int i =0; i< row; i++)  
		{  
            //scan first column, memorize the row id that contains O
			if(board[i][0] == 'O')  
			{  
				xIndex.push_back(i);  
				yIndex.push_back(0);  

			}
			
            //scan last column
			if(board[i][col-1] == 'O')  
			{  
				xIndex.push_back(i);  
				yIndex.push_back(col-1);  
			}  
		}  

		for(int i =0; i< col; i++)  
		{  
            //scan first row
			if(board[0][i] == 'O')  
			{  
				xIndex.push_back(0);  
				yIndex.push_back(i);  
			}  
			
            //scan last row
			if(board[row-1][i] == 'O')  
			{  
				xIndex.push_back(row-1);  
				yIndex.push_back(i);  
			}  
		}            
		
        //now based on the memorized boarder positions that are O
        //mark all of them Y. Note that xIndex and yIndex has the same size
        //scan neighboring nodes of those boarder nodes,
        //mark them as Y as well
		int k =0;  
		while(k<xIndex.size())  
		{  
            //note that the contents of xIndex and yIndex are updated
            //inside this while loop
			int x = xIndex[k];  
			int y = yIndex[k];     
			board[x][y] = 'Y';  
			if(x>0 && board[x-1][y] == 'O' ) {
				xIndex.push_back(x-1); 
				yIndex.push_back(y);
			}  
			if(x<row-1 && board[x+1][y] == 'O' ) {
				xIndex.push_back(x+1); 
				yIndex.push_back(y);
			}                 
			if(y>0 && board[x][y-1] == 'O' ) {
				xIndex.push_back(x); 
				yIndex.push_back(y-1);
			}  
			if(y<col-1 && board[x][y+1] == 'O' ) {
				xIndex.push_back(x); 
				yIndex.push_back(y+1);
			}  
			k++;  
		}  
		
        //change all existing O to X and Y to O
		for(int i =0; i< row; i++)  
		{  
			for(int j =0; j< col; j++)  
			{  
				if(board[i][j] =='O') board[i][j] = 'X';  
				if(board[i][j] == 'Y') board[i][j] = 'O';  
			}  
		}            
    }
};