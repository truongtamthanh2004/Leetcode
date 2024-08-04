class Solution {
public:
    int sum(vector<int>& nums, int start, int end) {
        int s = 0;
        for (int i = start; i <= end; i++) {
            s += nums[i];
            s = s % ((int)1e9 + 7);
        }

        return s;
    }
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;
        int time = 0;
        int i = 0, j = 0;
        while (time < n) {
            j = 0 + time;
            int s = sum(nums, i, j);
            while (j++ < n) {
                ans.push_back(s);

                if (j == n) break;

                s = (s + nums[j]) % ((int)1e9 + 7);
            }
            time++;
            i++;
        }

        sort(ans.begin(), ans.end());

        cout << ans.size();

        return sum(ans, left - 1, right - 1);
        
    }
};