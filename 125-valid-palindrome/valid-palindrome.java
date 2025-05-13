class Solution {
    public boolean isPalindrome(String s) {
        List<Character> list = new ArrayList<>();

        for (char i : s.toCharArray()) {
            if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9')) list.add(Character.toLowerCase(i));
        }

        int i = 0;
        int j = list.size() - 1;
        while (i < j) {
            if (list.get(i++) != list.get(j--)) return false;
        }

        return true;
    }
}