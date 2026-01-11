class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int[] cnt = new int[2];
        for (int i : students) cnt[i]++;

        for (int i : sandwiches) {
            if (cnt[i] > 0) cnt[i]--;
            else {
                return cnt[0] > 0 ? cnt[0] : cnt[1];
            }
        }

        return 0;
    }
}