class Solution {
public:
    int findMin(vector<int> a)
    {
        int m = a[0];
        for (auto i : a)
        {
            m = min(m, i);
        }
        return m;
    }
    int findMax(vector<int> a)
    {
        int m = a[0];
        for (auto i : a)
        {
            m = max(m, i);
        }
        return m;
    }
    int GCD(int a, int b)
    {
        while (a != b)
        {
            if (a > b) a -= b;
            else b -= a; 
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int mi = findMin(nums);
        int ma = findMax(nums);
        return GCD(mi, ma);
    }
};