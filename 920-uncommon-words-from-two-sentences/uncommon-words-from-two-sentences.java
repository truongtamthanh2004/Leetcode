class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        String[] words1 = s1.split(" ");
        String[] words2 = s2.split(" ");

        Map<String, Integer> count1 = new HashMap<>();
        Map<String, Integer> count2 = new HashMap<>();

        for(String w : words1) {
            if (count1.containsKey(w)) {
                count1.put(w, count1.get(w) + 1);
            }
            else {
                count1.put(w, 1);
            }
        } 

        for(String w : words2) {
            if (count2.containsKey(w)) {
                count2.put(w, count2.get(w) + 1);
            }
            else {
                count2.put(w, 1);
            }
        } 

        String[] ans = {};
        for (Map.Entry<String, Integer> entry : count1.entrySet()) {
            String key = entry.getKey();
            Integer value = entry.getValue();
            if (!count2.containsKey(key) && value == 1) {
                ans = Arrays.copyOf(ans, ans.length + 1);

                // Add a new element
                ans[ans.length - 1] = key;
            }
        }

        for (Map.Entry<String, Integer> entry : count2.entrySet()) {
            String key = entry.getKey();
            Integer value = entry.getValue();
            if (!count1.containsKey(key) && value == 1) {
                ans = Arrays.copyOf(ans, ans.length + 1);

                // Add a new element
                ans[ans.length - 1] = key;
            }
        }

        return ans;
    }
}