/**
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
    
 class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        if (num.empty()) return ret;
        std::sort(num.begin(), num.end());
        int n = num.size();
        vector<int> triplet(3);
        for (int i = 0; i < n; ++i) {
        	//remember this continue block
            if (i >0&& num[i] == num[i-1]) continue;
            
            int j = i+1;
            int k = n-1;
            while (j <k) {
                int sum = num[i] + num[j] + num[k];
                if (sum ==0) {
                    triplet[0] = num[i];
                    triplet[1] = num[j];
                    triplet[2] = num[k];
                    ret.push_back(triplet);
                    j ++;
                    k --;
                    //understand this two blocks
                    while (j <k && num[j] == num[j-1]) j++;
                    while (j <k &&num[k] == num[k+1]) k--;
                }
                else if(sum <0) {
                    j ++;
                }
                else {
                    k --;
                }
            }
        }
        return ret;
    }
};   