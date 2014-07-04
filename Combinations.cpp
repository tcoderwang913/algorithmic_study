/**
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    void combineUtil(vector<vector<int> >& ret, vector<int> combination, int n, 
    				int k, int level) {
        if (combination.size() == k) {
            ret.push_back(combination);
            return ;
        }
        
        for (int i = level; i <=n; ++i) {
            combination.push_back(i);
            combineUtil(ret, combination, n, k,i+1);
            combination.pop_back();
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        vector<int> combination;
        int level = 1;
        combineUtil(ret, combination, n, k, level);
        return ret;
    }
};