/**
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n ==0) return n;
        
        int i = 0;
        int count = 1 ;
        for (int j = 1; j < n; ++j) {
            if (A[j] == A[i]) {
            	//note that if block must be placed before count++
                if (count ==2) continue;
                 count ++;
            }
            else {
                count =1;
            }
            A[++i] = A[j];
        }
        return i+1;
    }
};