/**
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        vector<int> res(digits.size());
        for (int i = digits.size()-1; i >=0; --i) {
            res[i] = (digits[i] + carry) %10;
            carry = (digits[i] + carry)/10;
        }
        
        if (carry >0) res.insert(res.begin(), carry);
        return res;
    }
};