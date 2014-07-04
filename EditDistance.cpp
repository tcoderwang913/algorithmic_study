/**
Given two words word1 and word2, find the minimum number of steps required to 
convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
    	
    	vector<vector<int> > dist(m+1, vector<int>(n+1));
    	
    	dist[0][0] = 0;
    	for (int i = 1; i <=n; ++i) {
    		dist[0][i] = i;
    	}
    	
    	for (int i = 1; i <= m; ++i) {
    		dist[i][0] = i;
    	}
    	
    	for (int i =1; i <= m; ++i) {
    		for (int j = 1; j <=n; ++j ) {
    			dist[i][j] = INT_MAX;
    			if (word1[i-1] == word2[j-1] )
    				dist[i][j] =  dist[i-1][j-1];
    			dist[i][j] = std::min(dist[i][j], dist[i-1][j-1] + 1) ; //replace
    			dist[i][j] = std::min(dist[i][j], std::min(dist[i][j-1], dist[i-1][j]) +1);
    		}
    	}
    	return dist[m][n];
    }
};