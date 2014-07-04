/**
Given an array of integers, find two numbers such that they add up to a 
specific target number.

The function twoSum should return indices of the two numbers such that they add up
to the target, where index1 must be less than index2.
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        //map from array elem to indices, 1 based
        unordered_map<int, vector<int> > elemToIndexMap;
        for (size_t i = 0; i < numbers.size(); ++i) {
            elemToIndexMap[numbers[i]].push_back(i+1);
        }
        
        vector<int> res;
        for (int i = 0; i < numbers.size(); ++i)
        {
            unordered_map<int, vector<int> >::iterator it 
                        = elemToIndexMap.find(target - numbers[i]);
                        
            if (it == elemToIndexMap.end()) continue;
            
            int index1 = it->second[0], index2 = i + 1;
            
            if (numbers[i] == target - numbers[i]) { // two elements are the same
                if (it->second.size() == 1) 
                    continue;
                index2 = it->second[1];
            }
            
            vector<int> res;
            res.push_back(min(index1, index2));
            res.push_back(max(index1, index2));
            return res;
        }
        return res;
        
    }
};