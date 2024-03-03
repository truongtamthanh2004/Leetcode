class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();

        int res  = 0;
        for (int mask = 0; mask < (1 << m); mask++)
        {
            if (__builtin_popcount(mask) <= res) continue;
            if (check(n, requests, mask)) res = __builtin_popcount(mask);
        }
        return res;
    }

    bool check(int n, vector<vector<int>> req, int mask)
    {
        vector<int> count(n, 0);
        for (int i = 0; i < req.size(); i++)
        {
            if (testBit(mask, i))
            {
                count[req[i][0]]--;
                count[req[i][1]]++;
            }
        }
        for (auto i : count) 
        {
            if (i != 0) return false;
        }

        return true;
    }

    bool testBit(int mask, int i)
    {
        return ((mask >> i) & 1) == 1;
    }
};