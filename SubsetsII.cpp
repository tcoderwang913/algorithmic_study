/**
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    void subsetUtil(vector<vector<int> >& ret, vector<int> set, vector<int>&S, int pos) {
        ret.push_back(set);
        for (int i = pos; i < S.size(); ++i) {
            if (i != pos && S[i] == S[i-1]) continue;
            set.push_back(S[i]);
            subsetUtil(ret, set, S, i +1);
            set.pop_back();
        }
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ret;
        vector<int> set;
        std::sort(S.begin(), S.end());
        subsetUtil(ret, set, S, 0);
        return ret;
    }
};