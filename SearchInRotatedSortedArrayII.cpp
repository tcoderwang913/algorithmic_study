/**
Search in rotated sorted array with duplicates

worse case still linear, we can do linear search

*/

class Solution {
public:
    bool search(int A[], int n, int target) {
        int low = 0, high = n -1;
		while (low <= high) {
			int mid = low + (high - low) /2;
			if (A[mid] == target) return true;
			
			if (A[low] < A[mid] ) {
				if (A[low] <= target && target < A[mid]) {
					high = mid -1;
				}
				else {
					low = mid +1;
				}
			}
			else if (A[low] > A[mid]){
				if (A[mid] < target && target <= A[high] ) {
					low = mid +1;
				}
				else {
					high = mid -1;
				}
			}
			else {
			    low ++;
			}
		}	
		return false;
    }
};
