class Solution {
    public int minimumCost(int[] cost) {
        int n = cost.length;
        int[] cnt = new int[101];

        for (int i : cost) cnt[i]++;

        int k = 0;
        for (int i = 100; i >= 0; i--) {
            while (cnt[i] > 0) {
                cost[k++] = i;
                cnt[i]--;
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (i % 3 != 2) {
                sum += cost[i];
            }
        }

        return sum;
    }
}