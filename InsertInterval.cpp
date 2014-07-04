/**
Given a set of non-overlapping intervals, insert a new interval into the intervals 
(merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if (intervals.empty()) {
    		intervals.push_back(newInterval);
    		return intervals;
    	}
    	
    	Interval temp = newInterval;
    	vector<Interval> res;
    	for (size_t i = 0; i < intervals.size(); ++i) {
    		Interval currInterval = intervals[i];
    		
    		if (temp.end < currInterval.start) {
    			res.push_back(temp);
    			temp = currInterval;
    		}
    		else if (temp.start > currInterval.end) {
    			res.push_back(currInterval);
    		}
    		else {
    			temp.start = std::min(temp.start, currInterval.start);
    			temp.end   = std::max(temp.end, currInterval.end);
    		}
    	}
    	res.push_back(temp);
    	
    	return res;
    }
};