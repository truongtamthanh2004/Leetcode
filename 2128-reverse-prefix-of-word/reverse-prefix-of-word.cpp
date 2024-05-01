class Solution {
public:
    int findIndex(string word, char ch) {
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == ch) return i;
        }

        return -1;
    }
    string reversePrefix(string word, char ch) {
        int index = findIndex(word, ch);

        if (index == -1) return word;

        reverse(word.begin(), word.begin() + index + 1);

        return word;
    }
};