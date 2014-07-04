/**
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence
 where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        string result;
        vector<string> solutions;
        int len = s.size();
        vector<bool> possible(len+1, true); 
        // to record the search which has been executed once
        GetAllSolution(0, s, dict, len, result, solutions, possible);
        return solutions;
    }
     
    void GetAllSolution(int start, const string& s, const unordered_set<string> &dict, 
                        int len, string& result, vector<string>& solutions, 
                        vector<bool>& possible)
    {
        if (start == len)
        {
            solutions.push_back(result.substr(0, result.size()-1));
            //eliminate the last space
            return;
        }
        
        for (int i = start; i< len; ++i)
        {
            string piece = s.substr(start, i - start + 1);
            if (dict.find(piece) != dict.end() && possible[i+1]) 
            // eliminate unnecessory search
            {
                result.append(piece).append(" ");
                int beforeChange = solutions.size();
                GetAllSolution(i + 1, s, dict, len, result, solutions, possible);
                if(solutions.size() == beforeChange) 
                // if no solution, set the possible to false
                    possible[i+1] = false;
                result.resize(result.size() - piece.size()-1);
            }
        }
    }
};