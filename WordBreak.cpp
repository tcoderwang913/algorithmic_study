/**
Given a string s and a dictionary of words dict, determine if s can be segmented into 
a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/


class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> canBreak(s.size(), false);
    	canBreak[0] = true;
    	
    	for (int i = 1; i <= s.size(); ++i ) {
    		for (int j = 0; j < i; ++j) {
    			canBreak[i] = canBreak[j] && 
    							(dict.find(s.substr(j, i -j)) != dict.end());
    			if (canBreak[i]) {
    				canBreak[i] = true;
    				break;
    			}
    		}
    	}
    	return canBreak[s.size()];
    }
};
