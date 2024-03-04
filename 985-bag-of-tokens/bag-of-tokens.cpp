class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int left = 0;
        int right = n - 1;
        int maxScore = 0; // Keep track of the maximum score
        int score = 0; // Keep track of current score

        while (left <= right)
        {
            bool flag = false;
            if (tokens[left] <= power)
            {
                flag = true;
                score += 1;
                power -= tokens[left];
                left += 1;
                if (score > maxScore) maxScore = score;
            }
            else
            {
                if (score > 0)
                {
                    flag = true;
                    score -= 1;
                    power += tokens[right];
                    right -= 1;
                }
            }
            if (!flag) break;
        }
        return maxScore;
    }
};