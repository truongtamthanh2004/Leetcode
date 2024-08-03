class Solution {
public:
    // 1st solution
    bool checkAllElementsIn(vector<int>& target, vector<int>& arr) {
        for (auto i : target) {
            int cnt = count(arr.begin(), arr.end(), i);
            if (cnt == 0) return false;

            int cnt2 = count(target.begin(), target.end(), i);

            if (cnt != cnt2) return false;
        }

        return true;
    }

    // 2nd solution
    bool checkAllElementsIn2(vector<int>& target, vector<int>& arr) {
        vector<int> freq(1001, 0);
        int m = 0;

        for (int i = 0; i < target.size(); i++) {
            freq[target[i]]++;
            freq[arr[i]]--;
            m = max(m, max(target[i], arr[i]));
        }

        for (int i = 1; i <= m; i++) {
            if (freq[i] != 0) return false;
        }

        return true;
    }

    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // return checkAllElementsIn(target, arr);
        return checkAllElementsIn2(target, arr);
    }
};