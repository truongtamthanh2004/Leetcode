class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> cntMoney(2, 0);

        for (auto i : bills) {
            if (i == 20) {
                int remaining = 15;
                if (cntMoney[1] > 0) {
                    cntMoney[1]--;
                    remaining -= 10;
                }
                    
                while (remaining >= 5) {
                    if (cntMoney[0] == 0) return false;
                    cntMoney[0]--;
                    remaining -= 5;
                }
            }
            if (i == 10) {
                cntMoney[1]++;
                if (cntMoney[0] == 0) return false;
                cntMoney[0]--;
            }
            if (i == 5) cntMoney[0]++;
        }
        return true;
    }
};