class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        stack<vector<int>> s;
        s.push(points[0]);
        int n = points.size();
        for (int i = 1; i < n; i++)
        {
            vector<int> tmp = s.top();
            if (points[i][0] > tmp[1]) s.push(points[i]);
            else 
            {
                s.pop();
                tmp[0] = max(tmp[0], points[i][0]);
                tmp[1] = min(tmp[1], points[i][1]);
                s.push(tmp);
            }
        }
        return s.size();
    }
};