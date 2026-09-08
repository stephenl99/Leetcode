/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedules) {
        vector<vector<int>> real_intervals;
        for (vector<Interval> schedule : schedules) {
            for (Interval interval : schedule) {
                real_intervals.push_back({interval.start, interval.end});
            }
        }
        sort(real_intervals.begin(), real_intervals.end());
        vector<vector<int>> intervals = merge(real_intervals);
        vector<Interval> ans;
        for (int i = 0; i < intervals.size() - 1; i++) {
            ans.push_back(Interval(intervals[i][1], intervals[i + 1][0]));
        }
        return ans;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++) {
            if (i == 0) {
                ans.push_back(intervals[0]);
                continue;
            }
            if (intervals[i][1] <= ans[ans.size() - 1][1]) {
                continue;
            }
            else if (intervals[i][0] <= ans[ans.size() - 1][1]) {
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};