using ll = long long;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        ll t = 0;

        int i = 0;

        priority_queue<pair<int, int>> free; // weight, id
        priority_queue<pair<ll, int>> busy; // finish time, id

        for (int k = 0; k < n; k++) 
            free.push({-servers[k], -k});
        
        vector<int> ans;
        while (ans.size() < m)
        {
            while (busy.size() && -busy.top().first <= t) {
                int id = -busy.top().second;
                busy.pop();
                free.emplace(-servers[id], -id);
            }

            if (free.size()) {
                int id = -free.top().second;
                free.pop();
                ans.push_back(id);

                busy.emplace(-(t + tasks[i]), -id);
                i++;
                t = max(t, (ll)i);
            } 
            else {
                t = -busy.top().first;
            }
        }

        return ans;
    }
};