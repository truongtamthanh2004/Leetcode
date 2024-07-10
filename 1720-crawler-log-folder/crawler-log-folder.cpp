class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;
        for (auto i : logs) {
            if (i != "./" && i != "../") 
                s.push(i);
            if (i == "../" && !s.empty())
                s.pop();
        }

        return s.size();
    }
};