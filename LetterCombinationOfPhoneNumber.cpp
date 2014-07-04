/**
Given a digit string, return all possible letter combinations that the number
 could represent.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any 
order you want.


string letterToDigitMap[] = {"", " ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
*/

class Solution {
public:
    void letterCombinationsRecur(vector<string>& ret, string seq, string m[], 
    string& digits, int pos) {
        if (pos == digits.size()) {
            ret.push_back(seq);
            return ;
        }
        
        int currDigit = digits[pos] - '0';
        for (int i = 0; i < m[currDigit].size(); ++i) {
            seq.push_back(m[currDigit][i]);
            letterCombinationsRecur(ret, seq, m, digits, pos +1);
            seq.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string seq ="";
        string letterToDigitMap[] = {"", " ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        letterCombinationsRecur(ret, seq, letterToDigitMap, digits, 0);
        return ret;
    }
};