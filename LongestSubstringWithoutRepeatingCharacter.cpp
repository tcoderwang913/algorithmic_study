/**
Given a string, find the length of the longest substring without repeating characters. 

For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution{
public:
	int lengthOfLongestSubstring(string s) {
		bool visited[256] = {false};
		int i = 0, j = 0;
		int maxLen = INT_MIN;
		while (j < s.size()) {
			if (!visited[s[j]]) {
				visited[s[j++]] = true;
			}
			else {
				maxLen = std::max(maxLen, j -i);
				while (s[i] != s[j]){
					visited[s[i++]] = false;
				}
				i ++;
				j ++;
			}
		}
		
		return std::max(maxLen, j -i);
	}
};
