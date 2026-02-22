object Solution {
    def canConstruct(ransomNote: String, magazine: String): Boolean = {
        val mCounts = magazine.groupBy(identity).view.mapValues(e => e.length).toMap
        val rCounts = ransomNote.groupBy(identity).view.mapValues(e => e.length).toMap
        var res = true

        for ((char, count) <- rCounts) {
            if (mCounts.getOrElse(char, 0) < count) res = false
        }

        res
    }
}