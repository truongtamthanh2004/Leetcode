class Trie {
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
    };

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        if (word.empty()) return;

        TrieNode* cur = root;
        for (char ch : word) {
            int idx = toIdx(ch);

            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new TrieNode();
            }
            cur = cur->children[idx];
        }

        cur->isEndOfWord = true;
    }

    bool search(string word) {
        if (word.empty()) return false; // Sửa lỗi trả về giá trị hợp lệ

        TrieNode* cur = root;
        for (char ch : word) {
            int idx = toIdx(ch);

            if (cur->children[idx] == nullptr) {
                return false; // Không tìm thấy từ
            }
            cur = cur->children[idx];
        }

        return cur->isEndOfWord; // Kiểm tra cuối từ
    }

    bool startsWith(string prefix) {
        if (prefix.empty()) return false;

        TrieNode* cur = root;
        for (char ch : prefix) {
            int idx = toIdx(ch);

            if (cur->children[idx] == nullptr) {
                return false; // Không tìm thấy prefix
            }
            cur = cur->children[idx];
        }

        return true; // Tìm thấy prefix
    }

    int toIdx(char ch) { 
        return ch - 'a'; // Chuyển đổi ký tự sang chỉ số 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */