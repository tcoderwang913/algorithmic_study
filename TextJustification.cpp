/**
Given an array of words and a length L, format the text such that each line 
has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you
 can in each line. Pad extra spaces ' ' when necessary so that each line
  has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number 
of spaces on a line do not divide evenly between words, the empty slots on the left 
will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is 
inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. 
What should you do in this case?
In this case, that line should be left-justified.
*/

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;   
        if(0 == words.size()) return result;     
        int i =0;   
        while(i< words.size())   
        {   
            int start = i;   
            int sum = 0;   
            while(i<words.size() && sum + words[i].size()<=L)   
            {   
                sum+=words[i].size() +1;   
                i++;   
            }   
            int end = i-1;    
            int intervalCount = end - start;   
            int avgSp = 0, leftSp = 0;   
            if(intervalCount >0)   
            {   
                avgSp = (L-sum + intervalCount+1)/intervalCount;   
                leftSp = (L-sum + intervalCount+1)%intervalCount;   
            }      
            string line;      
            for(int j = start; j<end; j++)   
            {   
                line+=words[j];   
                if(i == words.size()) // the last line  
                    line.append(1, ' ');   
                else   
                {   
                    line.append(avgSp, ' '); //average space  
                    if(leftSp>0) // the extra space  
                    {   
                        line.append(1, ' ');   
                        leftSp--;   
                    }   
                }   
            }   

            line+=words[end];   
            if(line.size()<L)   
                line.append(L-line.size(), ' ');   
            result.push_back(line);      

        }   
        return result;  
    }
};