class Solution {
    public int minMutation(String startGene, String endGene, String[] bank) {
        Set<String> bankSet = new HashSet<>(Arrays.asList(bank));

        if (!bankSet.contains(endGene)) return -1;

        Queue<String> q = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        q.offer(startGene);
        visited.add(startGene);

        int mutations = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            mutations++;

            for (int i = 0; i < size; i++) {
                String cur = q.poll();

                List<String> neighbors = this.getNeighbors(cur);
                for (String neighbor : neighbors) {
                    if (visited.contains(neighbor) || !bankSet.contains(neighbor)) continue;

                    if (endGene.equals(neighbor)) return mutations;

                    visited.add(neighbor);
                    q.offer(neighbor);
                }
            }
        }

        return -1;
    }

    private List<String> getNeighbors(String s) {
        char[] genes = {'A', 'C', 'G', 'T'};
        char[] chars = s.toCharArray();
        List<String> res = new ArrayList<>();

        for (int i = 0; i < 8; i++) {
            char old = chars[i];

            for (char gene : genes) {
                if (gene == old) continue;
                chars[i] = gene;
                res.add(new String(chars));
            }

            chars[i] = old;
        }

        return res;
    }
}