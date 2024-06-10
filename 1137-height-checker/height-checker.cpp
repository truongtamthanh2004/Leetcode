class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expect;
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {
            expect.push_back(heights[i]);
        }
        ranges::sort(expect);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (expect[i] != heights[i]) count++;
        }
        return count;
    }
};