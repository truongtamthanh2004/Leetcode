class Solution {
public:
    string decimalToBinary(int n) {
        string binaryStr = "";
        
        // Edge case for 0
        if (n == 0) {
            return "0";
        }

        while (n > 0) {
            // Append '0' or '1' to the binary string
            binaryStr = to_string(n % 2) + binaryStr;
            n = n / 2;
        }

        return binaryStr;
    }
    int minBitFlips(int start, int goal) {
        string startStr = decimalToBinary(start);
        string goalStr = decimalToBinary(goal);

        int i = startStr.length() - 1;
        int j = goalStr.length() - 1;

        int cnt = 0;
        while (i >= 0 && j >= 0) {
            if (startStr[i--] != goalStr[j--]) cnt++;
        }

        while (i >= 0) {
            if (startStr[i--] != '0') cnt++;
        }

        while (j >= 0) {
            if (goalStr[j--] != '0') cnt++;
        }

        return cnt;
    }
};