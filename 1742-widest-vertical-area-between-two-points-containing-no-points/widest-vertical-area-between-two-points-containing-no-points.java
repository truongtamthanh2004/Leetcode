class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        Arrays.sort(points, (a, b) -> (a[0] >= b[0]) ? 1 : -1);

        int maxLength = 0;
        for (int i = 1; i < points.length; i++) {
            maxLength = Math.max(maxLength, points[i][0] - points[i - 1][0]);
        }

        return maxLength;
    }
}