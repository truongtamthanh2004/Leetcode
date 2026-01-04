class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length;
        int low = 0, high = (n / 2) - 1;
        int res = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[2 * mid] < nums[2 * mid + 1]) {
                high = mid - 1;
                res = 2 * mid;
            } else {
                low = mid + 1;
            }
        }

        return nums[res];
    }
}