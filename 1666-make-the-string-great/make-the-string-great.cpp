class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.length(); i++)
        {
            if (!st.empty())
            {
                if (abs(s[i] - st.top()) == 'a' - 'A') st.pop();
                else st.push(s[i]);
            }
            else st.push(s[i]);
            
        }
        string res = "";
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};