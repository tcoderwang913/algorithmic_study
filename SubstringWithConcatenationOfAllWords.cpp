/**
You are given a string, S, and a list of words, L, that are all of the same length. 
Find all starting indices of substring(s) in S that is a concatenation of each word in L 
exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (L.empty()) return res;
        
        map<string, int> need;
        map<string, int> find;
        
        int m = L.size();
        int len = L[0].size();
        
        vector<string>::iterator it = L.begin();
        for (; it != L.end(); ++it) {
            need[*it] ++;
        }
        
        for (int i = 0; i < (int)S.size() - m * len +1; ++i) {
            find.clear();
            int j = 0;
            for (; j < m; ++j) {
                string substr = S.substr(i + j *len, len);
                if (need.find(substr) != need.end()) {
                    find[substr] ++;
                }
                else {
                    break;
                }
                
                if (find[substr] > need[substr]) {
                    break;
                }
            }
            if (j ==m) res.push_back(i);
        }
        return res;
    }
};