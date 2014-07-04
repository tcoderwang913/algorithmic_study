/**
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/


 
class Solution {
public:
    struct sorter {
        bool operator() (const Interval& lhs, const Interval& rhs) {
            return lhs.start < rhs.start;
        }
    };
    
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        if (intervals.empty()) return ret;
        std::sort(intervals.begin(), intervals.end(), sorter());
        
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            Interval currInterval = ret.back();
            
            if (intervals[i].start > currInterval.end) {
                ret.push_back(intervals[i]);
            }
            else {
                ret.back().end = std::max(currInterval.end, intervals[i].end);
            }
        }
        return ret;
    }
};