class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> s;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            if (s.empty()) 
            {
                s.push({temperatures[i], i});
                ans.push_back(0);
            }
            else 
            {
                while (!s.empty() && temperatures[i] >= s.top().first)
                {
                    s.pop();
                }
                if (!s.empty())
                {
                    ans.push_back(s.top().second - i);
                }
                else ans.push_back(0);

                s.push({temperatures[i], i});
                
            }
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};