/**
Given n non-negative integers representing an elevation map where the width of
 each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


[解题思路]
对于任何一个坐标，检查其左右的最大坐标，然后相减就是容积。所以，
1. 从左往右扫描一遍，对于每一个坐标，求取左边最大值。
2. 从右往左扫描一遍，对于每一个坐标，求最大右值。
3. 再扫描一遍，求取容积并加和。
#2和#3可以合并成一个循环，

Find out left bound and right bound of each element
then compute the total amount of water being trapped
*/


class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0) return 0;
        int left[n];
        int right[n];

        int lmax = A[0];
        for (int i = 0; i < n; ++i)
        {
            lmax = max(lmax, A[i]);
            left[i] = lmax;
        }

        int rmax = A[n-1];
        for (int i = n - 1; i >= 0; --i)
        {
            rmax = max(rmax, A[i]);
            right[i] = rmax;
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
            res += min(left[i], right[i]) - A[i];

        return res;
    }
};