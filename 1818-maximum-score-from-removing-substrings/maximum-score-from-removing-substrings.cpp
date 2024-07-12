class Solution {
public:
    int calcScore(string& s, int point, char a, char b)
    {
        int score = 0;
        string result;

        for (char c : s)
        {
            if (!result.empty() && result.back() == b && c == a)
            {
                result.pop_back();
                score += point;
            }
            else
            {
                result.push_back(c);
            }
        }
        s = result;
        return score;
    }

    int maximumGain(string s, int x, int y) {
        int score = 0;
        
        if (x > y)
        {
            score += calcScore(s, x, 'b', 'a');
            score += calcScore(s, y, 'a', 'b');
        }
        else
        {
            score += calcScore(s, y, 'a', 'b');
            score += calcScore(s, x, 'b', 'a');
        }

        return score;
    }
};