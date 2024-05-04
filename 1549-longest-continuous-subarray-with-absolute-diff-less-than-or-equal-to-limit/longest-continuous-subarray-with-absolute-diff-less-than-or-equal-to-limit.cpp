class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        int n = nums.size();
        int j = 0;
        deque<int> dqmin, dqmax;

        for (int i = 0; i < n; i++)
        {
            while (dqmax.size() > 0 && dqmax.back() < nums[i]) dqmax.pop_back();

            while (dqmin.size() > 0 && dqmin.back() > nums[i]) dqmin.pop_back();

            dqmin.push_back(nums[i]);
            dqmax.push_back(nums[i]);

            int maxE = dqmax.front();
            int minE = dqmin.front();

            if (maxE - minE <= limit) ans = max(i - j + 1, ans);
            else 
            {
                if (nums[j] == dqmax.front()) dqmax.pop_front();
                if (nums[j] == dqmin.front()) dqmin.pop_front();
                j++;
            }
        }

        return ans;
    }
};