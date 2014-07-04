/**
Given a set of candidate numbers (C) and a target number (T), find all unique 
combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. 
(ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/


class Solution {
public:
    void combinationSumUtil(vector<vector<int> >& ret, vector<int> combination, 
    						vector<int>& candidates, int target,
                            int sum, int start) {
        if (sum > target) return ;
        if (sum == target) {
            ret.push_back(combination);
            return ;
        }           
        
        for (int i = start; i < candidates.size(); ++i) {
            sum += candidates[i];
            combination.push_back(candidates[i]);
            combinationSumUtil(ret, combination, candidates, target, sum, i);
            sum -= candidates[i];
            combination.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ret;
        vector<int> combination;
        int sum =0;
        int start = 0;
        std::sort(candidates.begin(), candidates.end());
        combinationSumUtil(ret, combination, candidates, target, sum, start) ;
        return ret;
    }
};