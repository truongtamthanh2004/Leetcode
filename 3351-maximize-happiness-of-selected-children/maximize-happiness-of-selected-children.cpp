class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());

        long long sum = 0;
        int n = happiness.size();
        for (int i = n - 1; i > n - 1 - k; i--)
        {
            if (happiness[i] - (n - 1 - i) > 0) sum += happiness[i] - (n - 1 - i);
            else return sum;
        }

        return sum;
    }
};