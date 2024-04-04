class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> res{1};
        while(res.size() < n)
        {
            vector<int> tmp;
            for (auto i : res) if (2 * i - 1 <= n) tmp.push_back(2 * i - 1);
            for (auto i : res) if (2 * i <= n) tmp.push_back(2 * i);
            res = tmp;
        }
        return res;
    }
};