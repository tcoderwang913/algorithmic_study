/**
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    int searchLeft(int A[], int n, int target) {
		int low = 0, high = n -1;
		int res = -1;
		while (low <= high) {
			int mid = low + (high - low) /2;
			if (A[mid] == target) {
				res = mid;
				high = mid -1;
			}
			else if (A[mid] < target) {
				low = mid +1;
			}
			else {
				high = mid -1;
			}
		}
		return res;
	}
	
	int searchRight(int A[], int n, int target) {
		int low = 0, high = n -1;
		int res = -1;
		while (low <= high) {
			int mid = low + (high - low) /2;
			if (A[mid] == target) {
				res = mid;
				low = mid +1;
			}
			else if (A[mid] < target) {
				low = mid +1;
			}
			else {
				high = mid -1;
			}
		}
		return res;
	}
	
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2,-1);
		res[0] = searchLeft(A,n, target);
		res[1] = searchRight(A, n, target);
		return res;
    }
};