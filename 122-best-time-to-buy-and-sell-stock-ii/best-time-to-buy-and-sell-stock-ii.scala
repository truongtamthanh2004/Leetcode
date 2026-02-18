object Solution {
    def maxProfit(prices: Array[Int]): Int = {
        var profit = 0

        for (i <- 1 until prices.length) {
            if (prices(i) > prices(i - 1)) {
                profit += prices(i) - prices(i - 1)
            }
        }

        profit
    }
}