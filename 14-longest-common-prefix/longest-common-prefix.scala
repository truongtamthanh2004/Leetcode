object Solution {
    def longestCommonPrefix(strs: Array[String]): String = {
        var firstStr = strs(0);
        var result = firstStr
        var found = false

        for (i <- 0 until firstStr.length if !found) {
            for (j <- 1 until strs.length if !found) {
                if (i >= strs(j).length) {
                    result = firstStr.substring(0, i);
                    found = true
                }
                else if (firstStr(i) != strs(j)(i)) {
                    result = firstStr.substring(0, i);
                    found = true
                }
            }
        }

        result;
    }
}