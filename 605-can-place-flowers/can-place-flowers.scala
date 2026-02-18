object Solution {
    def canPlaceFlowers(flowerbed: Array[Int], n: Int): Boolean = {
        var remaining = n
        val length = flowerbed.length
        for (i <- 0 until length) {
            if (flowerbed(i) == 0) {
                val leftEmpty = (i == 0) || (flowerbed(i - 1) == 0)
                val rightEmpty = (i == length - 1) || (flowerbed(i + 1) == 0)

                if (leftEmpty && rightEmpty) {
                    flowerbed(i) = 1
                    remaining -= 1
                }
            }
        }

        remaining <= 0
    }
}