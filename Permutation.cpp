/**
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

class Solution {
public:
    void permutationUtil(vector<vector<int> >&ret, vector<int>& num, int start) {
        if (start == num.size()) {
            ret.push_back(num);
            return ;
        }
        
        for (int i = start; i < num.size(); ++i) {
            std::swap(num[i],num[start]);
            permutationUtil(ret, num, start+1);
            std::swap(num[i],num[start]);
        }
        
    }
    
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        permutationUtil(ret,  num,0);
        return ret;
    }
};