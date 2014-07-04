/**
Given a string, determine if it is a palindrome, considering only alphanumeric 
characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask 
during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int low = 0, high = s.size() -1;
        while (low < high) {
            if (!isalnum(s[low])) {
                low ++;
                continue;
            }
            if (!isalnum(s[high])) {
                high --;
                continue;
            }
            if (tolower(s[low]) != tolower(s[high]) ) return false;
            else {
                low ++;
                high --;
            }
        }
        return true;
    }
};