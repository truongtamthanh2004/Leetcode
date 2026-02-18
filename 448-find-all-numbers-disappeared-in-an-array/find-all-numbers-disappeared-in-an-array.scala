object Solution {
    def findDisappearedNumbers(nums: Array[Int]): List[Int] = {
        var ans = List.newBuilder[Int]
        val n = nums.length
        val count = new Array[Int](n + 1)

        for (i <- 0 until n) {
            count(nums(i)) += 1
        } 

        for (i <- 1 until n + 1) {
            if (count(i) == 0) ans += i
        }

        ans.result()
    }
}