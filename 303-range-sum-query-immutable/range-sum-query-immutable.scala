class NumArray(private val nums: Array[Int]) {

    def sumRange(left: Int, right: Int): Int = {
        var sum = 0
        for (i <- left to right) sum += nums(i)

        sum
    }

}

/**
 * Your NumArray object will be instantiated and called as such:
 * val obj = new NumArray(nums)
 * val param_1 = obj.sumRange(left,right)
 */