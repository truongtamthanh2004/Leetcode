class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ranges::sort(nums);
        return nums[nums.size() / 2];
    }
};