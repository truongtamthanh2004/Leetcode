class Solution {
public:
    bool checkAllElementsIn(vector<int>& target, vector<int>& arr) {
        for (auto i : target) {
            int cnt = count(arr.begin(), arr.end(), i);
            int cnt2 = count(target.begin(), target.end(), i);

            if (cnt != cnt2) return false;
        }

        return true;
    }

    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        return checkAllElementsIn(target, arr);
    }
};