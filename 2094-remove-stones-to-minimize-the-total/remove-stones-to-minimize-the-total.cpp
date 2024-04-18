class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < piles.size(); i++)
        {
            pq.push(piles[i]);
        }

        int i = 0;
        while (i++ < k)
        {
            int cur = pq.top();
            pq.pop();

            if ((cur & 1) == 0)
                pq.push(cur / 2);
            else 
                pq.push(cur / 2 + 1);
        }

        int sum = 0;
        while (pq.size())
        {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};