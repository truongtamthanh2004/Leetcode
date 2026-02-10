class Solution {
    public int diagonalPrime(int[][] nums) {
        int n = nums.length;
        int maxPrime = 0;

        for (int i = 0; i < n; i++) {
            int val1 = nums[i][i];
            if (val1 > maxPrime && isPrime(val1)) maxPrime = val1;

            int val2 = nums[i][n - i - 1];
            if (val2 > maxPrime && isPrime(val2)) maxPrime = val2;
        }

        return maxPrime;
    }

    private boolean isPrime(int n) {
        if (n < 2) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }

        return true;
    }
}