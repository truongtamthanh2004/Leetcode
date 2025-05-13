class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : nums) {
            if (!map.containsKey(i)) {
                map.put(i, 1);
                continue;
            }
            map.put(i, map.get(i) + 1);
        }

        int maxKey = 0;
        int maxVal = 0;

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            Integer key = entry.getKey();
            Integer val = entry.getValue();
            
            if (maxVal < val) {
                maxVal = val;
                maxKey = key;
            }
        }

        return maxKey;
    }
}