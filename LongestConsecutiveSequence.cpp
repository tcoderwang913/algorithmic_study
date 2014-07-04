/**
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int,int> hashmap;
        for (int i = 0; i < num.size(); ++i) {
            hashmap[num[i]] =1;
        }
        
        int maxLen = INT_MIN;
        for (int i = 0; i < num.size(); ++i) {
            if (hashmap[num[i]]) {
                int len = 1;
                hashmap[num[i]] = 0;
            
                int left = num[i] -1;
                while (hashmap.count(left) && hashmap[left]) {
                    hashmap[left] = 0;
                    left --;
                    len ++;
                }
            
                int right = num[i] +1;
                while (hashmap.count(right) && hashmap[right]) {
                    hashmap[right] = 0;
                    right ++;
                    len ++;
                }
                maxLen = std::max(len, maxLen);
            }
            
        }
        return maxLen;
    }
};