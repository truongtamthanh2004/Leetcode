class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;
        int[] count = new int[n + 1];
        List<Integer> ans = new ArrayList<>();

        for (int num : nums) {
            count[num]++;
        }

        for (int i = 1; i < n + 1; i++) {
            if (count[i] == 0) ans.add(i);
        }

        return ans;
    }
}