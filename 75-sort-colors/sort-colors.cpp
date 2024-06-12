class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int n = nums.size();
        // for (int i = 0; i < n - 1; i++)
        // {
        //     for (int j = 1; j < n - i; j++)
        //     {
        //         if (nums[j] < nums[j - 1]) swap(nums[j], nums[j - 1]);
        //     }
        // }
        sort(nums.begin(), nums.end());
    }
};