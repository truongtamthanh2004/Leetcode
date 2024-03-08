class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // int maxElement = *max_element(nums.begin(), nums.end());
        // int minElement = *min_element(nums.begin(), nums.end());
        // vector<int> count(maxElement - minElement, 0);
        unordered_map<int, int> mp;
        for (auto i : nums) mp[i]++;
        int maxElement = 0;
        for (auto i : mp) 
        {
            maxElement = max(maxElement, i.second);
        }

        int count = 0;
        for (auto i : mp) 
        {
            if (maxElement == i.second) count += maxElement;
        }
        return count;
    }
};