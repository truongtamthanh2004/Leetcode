class Solution {
    public int countPrimeSetBits(int left, int right) {
        boolean[] isPrime = new boolean[21];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int p = 2; p * p <= 20; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= 20; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        int res = 0;
        for (int i = left; i <= right; i++) {
            if (isPrime[countSetBits(i)]) res++;
        }

        return res;
    }

    private int countSetBits(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += (n % 2);
            n /= 2;
        }

        return cnt;
    }
}