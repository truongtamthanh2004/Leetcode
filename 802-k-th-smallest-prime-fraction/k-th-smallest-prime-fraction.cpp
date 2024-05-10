class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int, int>> fraction;
        for(int i = 0; i < arr.size() - 1; i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                fraction.push_back({arr[i], arr[j]});
            }
        }

        std::sort(fraction.begin(), fraction.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return (double)a.first / a.second < (double)b.first / b.second;  // Return true if `a` should come before `b`
        });

        return {fraction[k - 1].first, fraction[k - 1].second};
    }
};