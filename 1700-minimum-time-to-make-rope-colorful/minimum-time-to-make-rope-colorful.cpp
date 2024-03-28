class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int pos = 0;
        int total = 0;
        for (int i = 0; i < colors.size();)
        {
            int sum = 0;
            int maxTime = 0;
            while (colors[pos] == colors[i])
            {
                sum += neededTime[pos];
                maxTime = max(maxTime, neededTime[pos]);
                pos++;
            }

            total += sum - maxTime;

            i = pos;
        }
        return total;
    }
};