class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> distances;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                distances.push_back(abs(nums[i] - nums[j]));
            }
        }

        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        return distances[k - 1];
    }
};