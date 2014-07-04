/**
Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order.
 (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

class Solution {
public:
    void combinationSumUtil(vector<vector<int> >&ret, vector<int> sol, 
    						vector<int>& num, int target, int sum, int pos) {
        if (sum > target) return ;
        if (sum == target) {
            ret.push_back(sol);
            return ;
        }
        for (int i = pos; i < num.size(); ++i) {
            sum += num[i];
            sol.push_back(num[i]);
            combinationSumUtil(ret, sol, num, target, sum, i+1);
            sum -= num[i];
            sol.pop_back();
            while (i +1 < num.size() && num[i] == num[i+1]) i++;
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ret;
        if (num.empty()) return ret;
        vector<int> combination;
        int sum = 0;
        std::sort(num.begin(), num.end());
        combinationSumUtil(ret, combination, num, target, sum, 0);
        return ret;
    }
};