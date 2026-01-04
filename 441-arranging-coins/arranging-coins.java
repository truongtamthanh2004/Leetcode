class Solution {
    public int arrangeCoins(int n) {
        // x = 1 -> 1
        // x = 2 -> 1 + 2
        // ...
        // 1 + 2 + 3 + ... + x = x (x + 1) / 2 <= n
        long low = 0, high = n;
        long res = 0;
        while (low <= high) {
            long mid = low + (high - low) / 2;

            if (mid * (mid + 1) / 2 == n) return (int)mid;
            else if (mid * (mid + 1) / 2 < n) {
                low = mid + 1;
                res = Math.max(res, mid);
            }
            else high = mid - 1;
        }

        return (int)res;
    }
}