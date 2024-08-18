class Solution {
public:
    bool isUgly(int n) {
        if (n < 1) return false;
        while (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
        {
            if (n % 5 == 0) n /= 5;
            if (n % 3 == 0) n /= 3;
            if (n % 2 == 0) n /= 2;
        }
        return n == 1;
    }
    int nthUglyNumber(int n) {
        if (n <= 1) return n;

        priority_queue<long> pq;
        unordered_set<long> seen;
        vector<int> primes = {2, 3, 5};

        pq.push(-1);
        seen.insert(1);

        long curUgly = 1;
        for (int i = 0; i < n; i++) {
            curUgly = -pq.top();
            pq.pop();

            for (auto i : primes) {
                long newUgly = i * curUgly;

                if (seen.find(newUgly) == seen.end()) {
                    seen.insert(newUgly);
                    pq.push(-newUgly);
                }
            }
        }

        return static_cast<int>(curUgly);
    }
};