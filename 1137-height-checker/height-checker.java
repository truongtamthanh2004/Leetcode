class Solution {
    public int heightChecker(int[] heights) {
        int n = heights.length;
        int[] expected = Arrays.copyOf(heights, n);

        int[] count = new int[101];
        for (int i : expected) {
            count[i]++;
        }

        int idx = 0;
        for (int i = 0; i <= 100; i++) {
            while (count[i] > 0) {
                expected[idx++] = i;
                count[i]--;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (expected[i] != heights[i]) cnt++;
        }

        return cnt;
    }
}