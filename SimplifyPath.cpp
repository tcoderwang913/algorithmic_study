/**
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, 
such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/


class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        assert(path[0] == '/'); //I forgot this statement
        
        //a trick to learn is to use vector to simulate stack behavior
        vector<string> S;
        int i = 0;
        
        
        while (i <n) {
            while (path[i] == '/' && i < n) i ++; //skip leading /s
            if (i == n) break; //if the string contains only ////, break
            
            int start = i; //not get the current path element
            while (path[i] != '/' && i < n) {
                i ++;
            }  
            int end = i-1;
            string substr = path.substr(start, end -start +1);
            
            //if the element is .. and stack not empty, pop top of stack
            //otherwise, if element is not ., push to stack
            if (substr == "..") {
                if (!S.empty())
                    S.pop_back();
            }
            else if (substr != ".") {
                S.push_back(substr);
            }
        }
        
        //recombine path, make sure to handle special case such as ///
        //or /../
        if (S.empty()) return "/";
        string simpPath = "";
        for (int i = 0; i < S.size(); ++i) {
            simpPath += "/" + S[i];
        }
        return simpPath;
        
    }
};