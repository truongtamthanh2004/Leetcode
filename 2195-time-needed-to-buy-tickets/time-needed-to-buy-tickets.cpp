class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int count = 0;
        while (tickets[k])
        {
            for (int i = 0; i < n; i++)
            {
                if (tickets[i])
                {
                    tickets[i]--;
                    count++;
                }
                if (i == k && !tickets[i]) return count;
            }
        }
        return count;
    }
};