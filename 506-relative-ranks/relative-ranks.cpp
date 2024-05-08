class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq; // store score and relative index respectively
        int n = score.size();
        for (int i = 0; i < score.size(); i++)
        {
            pq.push({score[i], i});
        }

        vector<string> ans(n);
        int rank = 0;
        while (!pq.empty())
        {
            rank++;
            int index = pq.top().second;
            pq.pop();

            if (rank == 1)
            {
                ans[index] = "Gold Medal";
                continue;
            }
            if (rank == 2)
            {
                ans[index] = "Silver Medal";
                continue;
            }
            if (rank == 3)
            {
                ans[index] = "Bronze Medal";
                continue;
            }

            ans[index] = to_string(rank);
        }

        return ans;
    }
};