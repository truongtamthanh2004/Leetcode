class Solution {
public:
    std::vector<std::string> split(const std::string& str, char delimiter) {
        std::vector<std::string> result;
        std::stringstream ss(str);
        std::string item;

        while (std::getline(ss, item, delimiter)) {
            result.push_back(item);
        }

        return result;
    }

    bool wordPattern(string pattern, string s) {
        vector<string> words = split(s, ' ');

        if (words.size() != pattern.length()) return false;

        unordered_map<string, char> mp;
        unordered_map<char, string> mp2;

        for(int i = 0; i < pattern.length(); i++) {
            if (mp.find(words[i]) != mp.end()) {
                if (mp[words[i]] != pattern[i]) return false;
            }
            else mp[words[i]] = pattern[i];

            if (mp2.find(pattern[i]) != mp2.end()) {
                if (mp2[pattern[i]] != words[i]) return false;
            }
            else mp2[pattern[i]] = words[i];
        }

        return true;
    }
};