class Solution {
    public int[] findEvenNumbers(int[] digits) {
        Set<Integer> set = new HashSet<>();
        int n = digits.length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i != j && j != k && i != k && digits[i] != 0) {
                        int sum = digits[i] * 100 + digits[j] * 10 + digits[k];

                        if ((sum & 1) == 0) set.add(sum);
                    }
                    
                }
            }
        }

        List<Integer> list = new ArrayList<>(set);
        Collections.sort(list);

        int[] res = list.stream().mapToInt(Integer::intValue).toArray();

        return res;
    }
}