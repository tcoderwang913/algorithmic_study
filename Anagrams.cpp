/**
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        if (strs.empty()) return vector<string>();
        map<string, vector<string> > hashmap;
		
		for (size_t i = 0; i < strs.size(); ++i) {
			string sortedStr = strs[i];
			std::sort(sortedStr.begin(), sortedStr.end());
			hashmap[sortedStr].push_back(strs[i]);
		}
		
		//iterate over the hash table and get output
		vector<string> ret;
		map<string, vector<string> >::iterator iter = hashmap.begin();
		for (; iter != hashmap.end(); ++iter) {
			if (iter->second.size() > 1) {
				for (size_t i = 0; i < iter->second.size(); ++i) {
					ret.push_back(iter->second[i]);
				}
			}
		}
		return ret;
    }
};