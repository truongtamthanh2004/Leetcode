class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> count;
        count[0] = 1;
        int curSum = 0;
        int totalSubarrays = 0;

        for (auto num : nums)
        {
            curSum += num;
            if (count.find(curSum - goal) != count.end())
            {
                totalSubarrays += count[curSum - goal];
            }
            count[curSum]++;
        }

        return totalSubarrays;
    }
};