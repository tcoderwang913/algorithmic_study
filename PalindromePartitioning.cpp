/**
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

class Solution {
public:
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            
            start ++;
            end --;
        }
        return true;
    }
    
    void partitionUtil(vector<vector<string> >& ret, vector<string> partition, 
    					string s, int start) {
        if (start == s.size()) {
            ret.push_back(partition);
            return ;
        }
        
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                partition.push_back(s.substr(start, i - start +1));
                partitionUtil(ret, partition, s, i+1);
                partition.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        vector<string> partition;
        partitionUtil(ret, partition, s, 0);
        return ret;
    }
};
  