/**
Given an array of non-negative integers, you are initially positioned at the first 
index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. 
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)

[Analysis]
Maintain a range that is reachable from the current i, update start and end of range 
when we iterate through the array
*/



class Solution {
public:
    int jump(int A[], int n) {
    	//note that we need to deal with n =1 in a special way
        if (n==1) return 0;
        
        int count = 0, start = 0, end = 0;
    	while (end <n) {
    		int max = 0;
    		count ++;
    		for (int i = start; i <= end; ++i) {
    			 if (A[i] + i >= n-1) return count;
    			 if (A[i] +i > max) max = A[i] + i;
    		}
    		start = end +1;
    		end = max;
    	}
    }
};
