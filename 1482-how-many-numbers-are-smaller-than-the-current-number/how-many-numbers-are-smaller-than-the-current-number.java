class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int n = nums.length;
        int[] count = new int[101];
        for (int i = 0; i < n; i++) {
            count[nums[i]]++;
        }

        int[] smallerCount = new int[101];
        for (int i = 1; i <= 100; i++) {
            smallerCount[i] = smallerCount[i - 1] + count[i - 1];
        }

        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = smallerCount[nums[i]];
        }

        return ans;
    }
}