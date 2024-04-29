class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return n;

        int i = 0;
        int j = 2;
        while (j < nums.size()) {
            if (nums[i] == nums[j]) {
                nums.erase(nums.begin() + j);
            }
            else {
                i++;
                j++;
            }
        }

        return nums.size();
    }
};