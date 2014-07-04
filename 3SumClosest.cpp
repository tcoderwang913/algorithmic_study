/**
Given an array S of n integers, find three integers in S such that the sum is closest 
to a given number, target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int res = INT_MAX;
        int n = num.size();
        std::sort(num.begin(), num.end());
        for (int i = 0; i <n-2; ++i) {
            int l = i+1, r = n-1;
            while (l <r) {
                int three_sum = num[i] + num[l] + num[r];
                if (three_sum == target) return target;
                else if (three_sum < target) l ++;
                else r --;
                
                if (res == INT_MAX || abs(three_sum - target) < abs(res - target)) {
                    res = three_sum;
                }
            }
        }
        return res;
    }
};