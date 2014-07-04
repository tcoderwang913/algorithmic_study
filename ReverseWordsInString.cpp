/**
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/

class Solution {
public:
    void reverseWords(string &s) {
        string res = "";
        string word = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] ==' ') {
                if (word.empty()) {
                    continue;
                }
                
                if (!word.empty()) {
                    res = word + " " + res;
                    word = "";
                    continue;
                }
            }else {
                word += s[i];
                continue;
            }
        }
        
        if (!word.empty()) {
            s = word + " " + res;
        }else {
            s = res;
        }
        
        s = s.substr(0, s.size()-1);
    }
};