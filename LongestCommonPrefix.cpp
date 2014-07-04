/**
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";
        std::sort(strs.begin(), strs.end());
        string res = "";
        for (int i = 0; i < strs[0].size(); ++i) {
            int ch = strs[0][i];
            bool match = true;
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[0][i] != strs[j][i]) {
                    match = false;
                    break;
                }
            }
            
            //don't forget the else block here
            if (match) {
                res += ch;
            }
            else {
                break;
            }
        }
        return res;
    }
};