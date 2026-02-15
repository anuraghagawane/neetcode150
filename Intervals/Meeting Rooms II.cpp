/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){
        //     return a.start < b.start;
        // });
        // priority_queue<int, vector<int>, greater<int>> minHeap;
        // int ans = 0;
        // for(const auto& interval: intervals) {
        //     if(minHeap.empty()) {
        //         minHeap.push(interval.end);
        //         continue;
        //     }

        //     int top = minHeap.top();
        //     if(top > interval.start) {
        //         minHeap.push(interval.end);
        //     }
        //     else {
        //         minHeap.pop();
        //         minHeap.push(interval.end);
        //     }
        // }

        // return minHeap.size();

        vector<int> start, end;
        for(const auto& interval: intervals) {
            start.push_back(interval.start);
            end.push_back(interval.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int res = 0, count = 0, s = 0, e = 0;
        while(s < start.size()) {
            if(start[s] < end[e]) {
                count++;
                s++;
            }
            else {
                count--;
                e++;
            }
            res = max(res, count);
        }

        return count;
    }
};
