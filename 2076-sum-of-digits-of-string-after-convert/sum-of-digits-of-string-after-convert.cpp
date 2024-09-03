class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;

        for (auto i : s) {
            int tmp = (i - 'a' + 1);
            
            while (tmp > 0) {
                res += (tmp % 10);
                tmp /= 10;
            }
        }
        k--;

        string tmp = to_string(res);

        while (k-- > 0) {
            res = 0;
            for (auto i : tmp) res += (i - '0');

            tmp = to_string(res);
        }

        return res;
    }
};