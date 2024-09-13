class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto i : queries) {
            int tmp = 0;
            for (int j = i[0]; j <= i[1]; j++) {
                tmp ^= arr[j];
            }

            ans.push_back(tmp);
        }

        return ans;
    }
};