class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty() || s[i] != ')')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                queue<char> q;
                while (st.top() != '(')
                {
                    q.push(st.top());
                    st.pop();
                }
                st.pop();
                while (!q.empty())
                {
                    st.push(q.front());
                    q.pop();
                }
            }
        }

        string res = "";
        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};