class Solution {
    public int minimumOperations(int[] nums) {
        int n = nums.length;
        int[] cnt = new int[101];

        for (int i : nums) {
            cnt[i]++;
        }

        int operationCount = 0;
        for (int i = 1; i <= 100; i++) {
            if (cnt[i] > 0) operationCount++;
        }

        return operationCount;
    }
}