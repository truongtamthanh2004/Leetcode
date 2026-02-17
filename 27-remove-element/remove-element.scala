object Solution {
    def removeElement(nums: Array[Int], value: Int): Int = {
        var count = 0
        for (i <- 0 until nums.length) {
            if (nums(i) != value) {
                nums(count) = nums(i)
                count += 1
            }
        }

        count
    }
}