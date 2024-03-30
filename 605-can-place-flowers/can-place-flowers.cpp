class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();

        if (m == 1)
        {
            if (flowerbed[0] == 1 && n == 1) return false;
            else return true;
        }

        for (int i = 0; i < m; i++)
        {
            if (flowerbed[i] == 0)
            {
                if (i == 0)
                {
                    if (flowerbed[i + 1] == 0)
                    {
                        n -= 1;
                        flowerbed[i] = 1;
                    }
                }
                else if (i == m - 1)
                {
                    if (flowerbed[i - 1] == 0)
                    {
                        n -= 1;
                        flowerbed[i] = 1;
                    }
                }
                else
                {
                    if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                    {
                        n -= 1;
                        flowerbed[i] = 1;
                    }
                }
            }
        }
        return n <= 0 ? true : false;
    }
};