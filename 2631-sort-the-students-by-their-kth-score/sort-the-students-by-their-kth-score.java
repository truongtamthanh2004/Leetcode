class Solution {
    public int[][] sortTheStudents(int[][] score, int k) {
        Arrays.sort(score, (a, b) -> (a[k] > b[k]) ? -1 : (a[k] < b[k]) ? 1 : 0);

        return score;
    }
}