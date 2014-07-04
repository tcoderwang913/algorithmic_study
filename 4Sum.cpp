/**
Given an array S of n integers, are there elements a, b, c, and d in S 
such that a + b + c + d = target? Find all unique quadruplets in the 
array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        if (num.empty() || num.size() < 4) return res;
        
        std::sort(num.begin(), num.end());
        vector<int> quadruplet(4);
        int n = num.size();
        for (int i = 0; i < n; ++i) {
            if (i >0 && num[i] == num[i-1]) continue;
            for (int j = i +1; j < n; ++j) {
                if (j >i+1 && num[j] == num[j-1]) continue;
                int l = j+1, r = n-1;
                while (l <r) {
                    int sum = num[i] + num[j] + num[l] + num[r];
                    if (sum == target) {
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[l];
                        quadruplet[3] = num[r];
                        res.push_back(quadruplet);
                        
                        l ++;
                        r --;
                        while (l <r && num[l] == num[l-1]) l++;
                        while (l <r && num[r] == num[r+1]) r--;
                    }
                    else if (sum < target) l ++;
                    else r--;
                }
            }
        }
        return res;
    }
};

    
    