/**
Given an array of non-negative integers, you are initially positioned at 
the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

一维DP，定义 jump[i]为从index 0 走到第i步时，剩余的最大步数。

那么转移方程可定义为
 jump[i] = max(jump[i-1], A[i-1]) -1, i!=0  
         = 0 , i==0  

然后从左往右扫描，当jump[i]<0的时候，意味着不可能走到i步，所以return false; 
如果走到最右端，那么return true.
*/

class Solution {
public:
    bool canJump(int A[], int n) {
        int maxCover = 0;
        for (int i = 0; i <= maxCover && i < n; ++ i) {
            if (A[i] + i > maxCover) 
                maxCover = A[i] + i;
            
            if (maxCover >= n-1) return true;
        }
        return false;
    }
};