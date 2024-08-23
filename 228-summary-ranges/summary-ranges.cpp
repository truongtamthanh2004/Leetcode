class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        int i = 0;
        while (i < nums.size()) {
            int last = 0;
            int j = 0;
            for (j = i + 1; j < nums.size(); j++) {
                if (nums[j] - 1 != nums[j - 1]) break;
                last = nums[j];
            }
            string tmp = (nums[i] != nums[j - 1] ? to_string(nums[i]) + "->" + to_string(nums[j - 1]) : to_string(nums[i]));
            ans.push_back(tmp);
            i = j;
        }

        return ans;
    }
};