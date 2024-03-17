class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        int n = intervals.size();
        int i = 0;

        // Binary search to find the insertion point for newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            merged.push_back(intervals[i]);
            i++;
        }

        // Merge newInterval with overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        merged.push_back(newInterval);

        // Merge remaining intervals with newInterval if necessary
        while (i < n) {
            merged.push_back(intervals[i]);
            i++;
        }

        return merged;
    }
};