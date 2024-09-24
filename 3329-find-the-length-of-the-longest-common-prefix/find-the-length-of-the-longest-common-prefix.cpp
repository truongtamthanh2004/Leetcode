class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> prefixMap;

        for (auto num : arr1) {
            string str = to_string(num);
            string pre = "";
            for (auto i : str) {
                pre += i;
                prefixMap[pre]++;
            }
        }

        int maxLength = 0;

        for (auto num : arr2) {
            string str = to_string(num);
            string pre = "";
            for (auto i : str) {
                pre += i;
                if (prefixMap.find(pre) != prefixMap.end()) {
                    maxLength = max(maxLength, (int)pre.length());
                }
            }
        }

        return maxLength;
    }
};