/**
Find the contiguous subarray within an array (containing at least one number) 
which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using 
the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
    int max(int a, int b, int c) {
        return std::max(std::max(a,b),c);
    }
    
    int maxSubArrayCross(int A[], int l, int m, int h) {
        int sum = 0;
        int leftSum = INT_MIN;
        for (int i = m; i >=l; --i) {
            sum += A[i];
            if (sum > leftSum) leftSum = sum;
        }
        
        sum =0;
        int rightSum = INT_MIN;
        for (int i = m+1; i <=h; ++i) {
            sum += A[i];
            if (sum > rightSum) rightSum = sum;
        }
        
        return leftSum + rightSum;
    }
    
    int maxSubArrayUtil(int A[], int l, int h){
        if (l ==h) return A[l];
        
        int m = l + (h -l) /2;
        
        return max(maxSubArrayUtil(A, l, m),
                   maxSubArrayUtil(A, m+1, h),
                   maxSubArrayCross(A, l, m, h));
    }
    
    int maxSubArray(int A[], int n) {
        return maxSubArrayUtil(A, 0, n-1);
    }
};

//The following solution is DP
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0;
        int maxSum = INT_MIN;
        for (int i = 0; i < n; ++i) {
            sum = std::max(sum + A[i], A[i]);
            maxSum = std::max(sum, maxSum);
        }
        return maxSum;
    }
};