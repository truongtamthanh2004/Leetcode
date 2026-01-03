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

        k = 0;
        int sum = 0;
        while (k < n) {
            int i = 0;
            while (i < 3 && k < n) {
                if (i == 2) {
                    k++;
                    break;
                }
                
                sum += cost[k++];
                i++;
            }
        }

        return sum;
    }
}