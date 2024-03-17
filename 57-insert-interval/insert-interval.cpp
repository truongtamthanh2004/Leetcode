class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        int index = 0;
        
        while (index < n && intervals[index][1] < newStart) 
            ans.push_back(intervals[index++]);

        while (index < n && newEnd >= intervals[index][0])
        {
            newStart = min(newStart, intervals[index][0]);
            newEnd = max(newEnd, intervals[index][1]);
            index += 1;
        }
        ans.push_back({newStart, newEnd});

        while (index < n) 
            ans.push_back(intervals[index++]);

        return ans;        
    }
};