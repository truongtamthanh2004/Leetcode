class Solution {
public:
    
    int countPrimes(int n) {
        vector<bool> p(n + 1, true);
        p[0] = false;
        p[1] = false;
        for (int i = 2; i * i <= n; i++)
        {
            if (p[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    p[j] = false;
                }
            }
        }
        return (int)count(p.begin(), p.end() - 1, true);
    }
};