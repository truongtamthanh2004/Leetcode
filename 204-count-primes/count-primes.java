class Solution {
    public int countPrimes(int n) {
        if (n < 1) return 0;

        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;

        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    isPrime[i] = false;
                } 
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime[i]) res++;
        }

        return res;
    }
}