class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<tuple<int, int, int>> sortedTasks;
        int n = tasks.size();
        for (int i = 0; i < n; i++)
            sortedTasks.emplace_back(tasks[i][0], tasks[i][1], i);
        
        sort(sortedTasks.begin(), sortedTasks.end());

        long long t = 0;
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        int i = 0;

        while (res.size() < n)
        {
            while (i < n)
            {
                auto [enqTime, procTime, id] = sortedTasks[i];
                if (enqTime <= t)
                {
                    pq.push({-procTime, -id});
                    i++;
                } else break;
            }

            if (pq.size())
            {
                auto [procTime, id] = pq.top();
                pq.pop();
                t -= procTime;
                res.push_back(-id);
            } else {
                t = get<0>(sortedTasks[i]);
            }
        }

        return res;
    }
};