class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;

        int pos = 0;
        for (pos = 0; pos < strs[0].length(); pos++) {
            boolean identical = true;
            for (int j = 1; j < n; j++) {
                if (strs[j - 1].length() <= pos || strs[j].length() <= pos) {
                    identical = false;
                    break;
                }
                if (strs[j - 1].charAt(pos) != strs[j].charAt(pos)) {
                    identical = false;
                    break;
                }
            }

            if (!identical) break;
        }

        return strs[0].substring(0, pos);
    }
}