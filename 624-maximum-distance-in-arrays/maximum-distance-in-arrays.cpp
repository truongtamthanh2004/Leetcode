class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int, int>> minE;
        vector<pair<int, int>> maxE;
        for (int i = 0; i < arrays.size(); i++) {
            maxE.push_back({arrays[i][arrays[i].size() - 1], i});
            minE.push_back({arrays[i][0], i});
        }
        sort(minE.begin(), minE.end());
        sort(maxE.begin(), maxE.end());

        int j = (int)arrays.size() - 1, i = 0;
        while (i <= j) {
            if (maxE[j].second != minE[i].second) return abs(maxE[j].first - minE[i].first);

            if (maxE[j].first - maxE[j - 1].first > minE[i + 1].first - minE[i].first) i++;
            else j--;
        }
        return 0;
    }
};