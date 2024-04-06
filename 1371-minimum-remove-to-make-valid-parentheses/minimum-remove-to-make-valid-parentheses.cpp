class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string res = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            if (s[i] == ')')
            {
                if (!st.empty()) st.pop();
                else 
                {
                    s.erase(i, 1);
                    i--;
                }
            }
        }

        while (!st.empty()) st.pop();

        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ')')
            {
                st.push(s[i]);
            }
            if (s[i] == '(')
            {
                if (!st.empty()) st.pop();
                else 
                {
                    s.erase(i, 1);
                }
            }
        }
        return s;
    }
};