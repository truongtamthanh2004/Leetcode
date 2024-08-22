class Solution {
public:
    string decimalToBinary(int n) {
        if (n == 0) return "0";

        std::string binary = "";
        while (n > 0) {
            binary = (n & 1 ? "1" : "0") + binary;  // Check the least significant bit and prepend
            n >>= 1;  // Right shift n by 1 bit (equivalent to n /= 2)
        }

        return binary;
    }

    void flip(string& binary) {
        for (auto& i : binary) {
            if (i == '0') i = '1';
            else i = '0';
        }
    }

    int binaryToDecimal(string &binary) {
        int decimal = 0;
        int length = binary.length();

        for (int i = 0; i < length; ++i) {
            if (binary[length - i - 1] == '1') {
                decimal += 1 << i;  // 1 << i is the same as pow(2, i)
            }
        }

        return decimal;
    }
    int findComplement(int num) {
        string binary = decimalToBinary(num);

        flip(binary);

        return binaryToDecimal(binary);
    }
};