class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0;
        for (auto i : words) {
            bool check = true;
            for (int j = 0; j < i.length(); j++) {
                if (allowed.find(i[j]) == std::string::npos) {
                    check = false;
                    break;
                }
            }
            if (check) cnt++;
        }
        return cnt;
    }
};