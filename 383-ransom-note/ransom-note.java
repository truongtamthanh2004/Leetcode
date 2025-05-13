class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> map1 = new HashMap<>();
        Map<Character, Integer> map2 = new HashMap<>();

        for (Character i : ransomNote.toCharArray()) {
            if (map1.containsKey(i)) {
                map1.put(i, map1.get(i) + 1);
            }
            else {
                map1.put(i, 1);
            }
        }

        for (Character i : magazine.toCharArray()) {
            if (map2.containsKey(i)) {
                map2.put(i, map2.get(i) + 1);
            }
            else {
                map2.put(i, 1);
            }
        }

        for (Map.Entry<Character, Integer> entry : map1.entrySet()) {
            Character key = entry.getKey();
            Integer value = entry.getValue();

            if (!map2.containsKey(key) || map2.get(key) < value) return false;
        }

        return true;
    }
}