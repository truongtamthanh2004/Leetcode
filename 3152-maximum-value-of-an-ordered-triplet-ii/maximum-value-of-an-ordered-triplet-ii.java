class Solution {
    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        if (n < 3) return 0;

        int[] maxLeft = new int[n];
        int[] maxRight = new int[n];
        maxLeft[0] = nums[0];
        maxRight[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) maxLeft[i] = Math.max(nums[i], maxLeft[i - 1]);
        for (int i = n - 2; i >= 0; i--) maxRight[i] = Math.max(nums[i], maxRight[i + 1]);

        long res = 0;
        for (int i = 1; i < n - 1; i++) {
            res = Math.max(res, (long)(maxLeft[i - 1] - nums[i]) * maxRight[i + 1]);
        }

        return res;
    }
}