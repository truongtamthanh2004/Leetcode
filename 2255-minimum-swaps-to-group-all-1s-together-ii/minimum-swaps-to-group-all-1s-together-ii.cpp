class Solution {
public:
    int countDigitOne(vector<int>& nums) {
        int count = 0;
        for (auto i : nums) {
            if (i == 1) count++;
        }
        return count;
    }

    int countDigitZero(vector<int>& nums, int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) count++;
        }
        return count;
    }
    int minSwaps(vector<int>& nums) {
        int countOne = countDigitOne(nums);
        nums.insert(nums.end(), nums.begin(), nums.end());
        int countZero = countDigitZero(nums, countOne);

        int i = 0; 
        int j = countOne - 1;
        int ans = countZero;
        while (j < nums.size()) {
            ans = min(ans, countZero);

            i++;
            j++;

            if (j >= nums.size()) break;
            
            if (nums[j] == 0) countZero++;
            if (nums[i - 1] == 0) countZero--;
        }

        return ans;
    }
};