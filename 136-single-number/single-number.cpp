class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // ranges::sort(nums);
        // int count = 1;
        // for (int i = 1; i < nums.size(); i++)
        // {
        //     if (nums[i] == nums[i - 1])
        //     {
        //         count++;
        //     }
        //     else 
        //     {
        //         if (count == 1) return nums[i - 1];
        //         count = 1;
        //     }
        // }
        // return nums[nums.size() - 1];

        int ans = 0;
        for (auto x : nums)
            ans = ans^x;
        return ans;
    }
};