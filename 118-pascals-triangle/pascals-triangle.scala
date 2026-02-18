object Solution {
    def generate(numRows: Int): List[List[Int]] = {
        var result = List(List(1))

        for (i <- 1 until numRows) {
            val prevRow = result.last
            val newRow = List.newBuilder[Int]

            newRow += 1

            for (j <- 1 until prevRow.length) {
                newRow += prevRow(j - 1) + prevRow(j)
            }

            newRow += 1

            result = result :+ newRow.result()
        }

        result
    }
}