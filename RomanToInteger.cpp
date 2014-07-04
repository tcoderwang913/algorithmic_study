/**
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

[Analysis]
The way to write the following code is learned from Annie Kim.
*/

class Solution {
public:
    int romanToInt(string s) {
    	//store the mapping from roman literals to integer in a map
        unordered_map<char, int> roman;
        roman['M'] = 1000;
        roman['D'] = 500;
        roman['C'] = 100;
        roman['L'] = 50;
        roman['X'] = 10;
        roman['V'] = 5;
        roman['I'] = 1;
        
        int res = 0, N = s.size();
        //check for whether the value is smaller than the roman literal in its right
        for (int i = 0; i < N; ++i) {
            if (i < N-1 && roman[s[i]] < roman[s[i+1]]) {
                res -=  roman[s[i]];
            }
            else {
                res += roman[s[i]];
            }
        }
        
        return res;
    }
};

