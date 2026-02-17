object Solution {
    def scoreOfString(s: String): Int = {
        var sum = 0;
        for (i <- 0 until s.length - 1) {
            sum += (s(i) - s(i + 1)).abs
        }

        sum;
    }
}