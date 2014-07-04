/**
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    void subUtil(vector<vector<int> >&ret, vector<int> set, vector<int>& S, int start) {
        ret.push_back(set);
        for (int i = start; i < S.size(); ++i) {
            set.push_back(S[i]);
            subUtil(ret, set, S, i+1);
            set.pop_back();
        }
    }
    
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ret;
        vector<int> set;
        std::sort(S.begin(), S.end());
        subUtil(ret, set, S,0);
        return ret;
    }
};