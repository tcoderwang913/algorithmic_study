/**
Given a string S and a string T, find the minimum window in S which will contain all
 the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only 
one unique minimum window in S.
*/

class Solution {
public:
    string minWindow(string S, string T) {
        if (S.size() ==0 || S.size() < T.size()) return "";
        int need[256] = {0};
        int find[256] = {0};
        
        for (int i = 0; i < T.size(); ++i) {
            need[T[i]] ++;
        }
        
        int count = 0, resStart = -1, resEnd = S.size();
        for (int start = 0, end = 0; end < S.size(); ++ end) {
            if (need[S[end]] >0) {
                find[S[end]] ++;
                if (find[S[end]] <= need[S[end]]) count ++;
            }
            
            if (count == T.size()) {
                while (find[S[start]] > need[S[start]] || need[S[start]] ==0) {
                    find[S[start]] --;
                    start ++;
                }
                
                if (end - start < resEnd - resStart) {
                    resStart = start;
                    resEnd = end;
                }
            }
        }
        
        return (resStart == -1)? "" : S.substr(resStart, resEnd - resStart +1);
    }
};