object Solution {
    def myAtoi(str: String): Int = {
        var s = str.trim;

        if (s.isEmpty) return 0;
        var sign = 1;

        if (s(0) == '+' || s(0) == '-') {
            if (s(0) == '-') sign = -1;
            s = s.substring(1);
        }

        var i = 0;
        var res = 0;
        while (i < s.length && s(i).isDigit) {
            val digit = s(i) - '0';

            if (res > (Int.MaxValue - digit) / 10) {
                return if (sign == 1) Int.MaxValue else Int.MinValue;
            }

            res = res * 10 + digit;
            i += 1;
        }

        return res * sign;
    }
}