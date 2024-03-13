class Solution {
public:
    
    int pivotInteger(int n) {
        if (n == 1) return 1;
        
        int sumAbove = n * (n + 1) / 2;
        int sumBelow = 1;

        for (int i = 2; i <= n; i++)
        {
            sumAbove -= (i - 1);
            sumBelow += i;
            if (sumAbove == sumBelow) return i;
        }

        return -1; // No such integer exist
    }
};