/**
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    string intToRoman(int num) {
        string t[] = {"", "M", "MM", "MMM"};
        string h[] = {"", "C", "CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ten[] = {"", "X","XX","XXX","XL","L","LX","LXX", "LXXX","XC"};
        string s[] = {"","I","II","III","IV","V", "VI","VII","VIII","IX"};
        
        string res = "";
        res += t[num/1000];
        res += h[num%1000/ 100];
        res += ten[num%100/10];
        res += s[num%10];
        return res;
    }
};