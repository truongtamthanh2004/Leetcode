class Solution {
    private Set<Integer> seen = new HashSet<>();

    public boolean isHappy(int n) {
        int sum = 0;

        while (n > 0) {
            int tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }

        if (seen.contains(sum)) return false;
        if (sum == 1) return true;

        seen.add(sum);

        return isHappy(sum);
    }
}