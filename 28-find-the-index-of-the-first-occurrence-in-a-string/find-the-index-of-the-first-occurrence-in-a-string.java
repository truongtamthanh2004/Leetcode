class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.length() > haystack.length()) return -1;

        // if (needle.length() == haystack.length() && needle.equals(haystack)) return 0;

        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            if (haystack.charAt(i) == needle.charAt(0)) {
                String sub = haystack.substring(i, i + needle.length());
                if (sub.equals(needle)) return i;
            }
        }

        return -1;
    }
}