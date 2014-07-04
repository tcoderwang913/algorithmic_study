/**
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string countAndSay(int n) {
        string seq = "1";
        
        int iter = 1;
        while (iter <n) {
            stringstream ss;
            int count = 0;
            char last = seq[0];
    		
    		//the key is to use stringstream and loop to seq.size() with equal
            for (int i = 0; i <= seq.size(); ++i)
            {
                if (seq[i] == last)
                {
                    ++count;
                }
                else
                {
                    ss << count << last;
                    count = 1;
                    last = seq[i];
                }
            }
            seq = ss.str();
            iter++;
        }
        return seq;
    }
};