class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 2; i++)
        {
            if ((arr[i] & 1) == 1)
            {
                int cnt = 1;
                for (int j = i + 1; j <= i + 2; j++)
                {
                    if ((arr[j] & 1) == 0) break;
                    cout << arr[j] << " ";
                    cnt++;
                }
                if (cnt == 3) return true;
            }
        }
        return false;
    }
};