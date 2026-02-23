object Solution {
    def sumOfDigits(n: Int): Int = {
            n.toString.map(_.asDigit).sum
    }

    def countBalls(lowLimit: Int, highLimit: Int): Int = {
        (lowLimit to highLimit).map(sumOfDigits).groupBy(identity).map { case (_, balls) => balls.length }.max
    }
}