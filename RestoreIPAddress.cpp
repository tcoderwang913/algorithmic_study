/**
Given a string containing only digits, restore it by returning all possible 
valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

class Solution {
public:
    bool isValid(string s) {
    	//note the rules of a valid ip address
		if (s.size() ==3 && (atoi(s.c_str()) ==0 || atoi(s.c_str()) > 255)) return false;
		if (s.size() ==3 && s[0] == '0' ) return false;
		if (s.size() ==2 && s[0] == '0' ) return false;
		if (s.size() ==2 && atoi(s.c_str()) ==0) return false;
        return true;
	}
	
	void getRes(vector<string>& res, string ip, string s, int m) {
		//each ip address has 4 parts and each part has length 1 up to 3
		if (m ==0) {
			//need to make sure that we don't have any digit remain
			if (s.empty())
				res.push_back(ip);
			return ;
		}
		
		//iterate over the length of each part
		for (int i = 1; i <=3; ++i) {
			if (s.size() >= i && isValid(s.substr(0,i))) {
				if (m ==1) {
					getRes(res, ip + s.substr(0,i), s.substr(i), m-1);
				}
				else {
					getRes(res, ip + s.substr(0,i) + ".", s.substr(i), m -1);
				}
			}
		}
	}
	 
	vector<string> restoreIpAddresses(string s) {
		vector<string> ret;
		string  ip= "";
		getRes(ret, ip, s, 4);
		return ret; 
	}
};