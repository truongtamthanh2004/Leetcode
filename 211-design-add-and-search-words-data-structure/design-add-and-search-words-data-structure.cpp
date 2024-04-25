class WordDictionary {
public:
    class TrieNode {
    public:
        TrieNode** children; // Mảng con trỏ
        bool isEndOfWord;

        TrieNode() {
            children = new TrieNode*[26]; // Khởi tạo mảng con trỏ
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr; // Đặt mỗi con trỏ thành nullptr
            }
            isEndOfWord = false;
        }

        ~TrieNode() { // Destructor để tránh rò rỉ bộ nhớ
            for (int i = 0; i < 26; ++i) {
                if (children[i] != nullptr) {
                    delete children[i];
                }
            }
            delete[] children; // Xóa mảng
        }

        bool search(string word, int fromPos) {
            if (word.length() == 0) return false;

            TrieNode* cur = this;
            for (int i = fromPos; i < word.length(); i++) {
                char ch = word[i];
                if (ch == '.') {
                    for (int j = 0; j < 26; j++) {
                        TrieNode* child = cur->children[j];
                        if (child && child->search(word, i + 1)) {
                            return true;
                        }
                    }

                    return false;
                } else {
                    int idx = ch - 'a';
                    if (!cur->children[idx]) {
                        return false;
                    }

                    cur = cur->children[idx];
                }
            }

            return cur->isEndOfWord;
        }
    };

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        if (word.empty()) return;

        TrieNode* cur = root;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            int idx = ch - 'a';
            
            if (!cur->children[idx]) cur->children[idx] = new TrieNode();
            
            cur = cur->children[idx];
        }

        cur->isEndOfWord = true;
    }
    
    bool search(string word) {
        return root->search(word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */