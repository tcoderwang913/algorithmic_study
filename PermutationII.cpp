/**
Given a collection of numbers that might contain duplicates, return all possible 
unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

class Solution {
public:
	//spend some more time try to understand this one
    void permuteUtil(vector<vector<int> >& ret, vector<int> perm, vector<int>& num, 
    				vector<bool>& visited) {
        if (perm.size() == num.size()) {
            ret.push_back(perm);
            return ;
        }
        
        for (int i = 0; i < num.size(); ++i) {
            if (visited[i] ||(i >0 && num[i] == num[i-1] && visited[i-1]) ) continue;
            perm.push_back(num[i]);
            visited[i] = true;
            permuteUtil(ret, perm, num, visited);
            perm.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ret;
        if (num.empty()) return ret;
        std::sort(num.begin(), num.end());a
        vector<bool> visited(num.size(), false);
        vector<int> perm;
        permuteUtil(ret, perm, num, visited);
        return ret;
    }
};