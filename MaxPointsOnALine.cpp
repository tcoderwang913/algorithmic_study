/**
Given n points on a 2D plane, find the maximum number of points that lie on 
the same straight line.

[Analysis]
The idea is to use hashmap to store the lines that have the same slope.
Meanwhile, store the slope as vertical lines as INT_MAX
*/


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        unordered_map<float,int> stat;
        int maxNum = 0;
        
        for (int i = 0; i < points.size(); ++i) {
            stat.clear();
            int duplicates = 1;
            stat[INT_MAX] = 0;
            for (int j = 0; j < points.size(); ++j) {
                if (j ==i) continue;
                
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    duplicates ++;
                    continue;
                }
                
                float slope = (points[j].x - points[i].x ==0) ? INT_MAX :
                        (float) (points[j].y - points[i].y)/(points[j].x - points[i].x);
                
                stat[slope] ++;
            }
            
            //get current maxNum
            auto iter = stat.begin();
            for (; iter != stat.end(); ++ iter) {
                maxNum = std::max(maxNum, iter->second + duplicates);
            }
        }
        return maxNum;
    }
};