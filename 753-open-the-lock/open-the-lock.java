class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> deadSet = new HashSet<>(Arrays.asList(deadends));

        if (deadSet.contains("0000")) return -1;

        Queue<String> q = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        q.offer("0000");
        visited.add("0000");

        int steps = 0;
        while (!q.isEmpty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                String cur = q.poll();

                if (cur.equals(target)) return steps;

                List<String> neighbors = getNeighbors(cur);
                for (String neighbor : neighbors) {
                    if (visited.contains(neighbor) || deadSet.contains(neighbor)) continue;

                    q.offer(neighbor);
                    visited.add(neighbor);
                }
            }

            steps++;
        }

        return -1;
    }

    private List<String> getNeighbors(String s) {
        List<String> res = new ArrayList<>();
        char[] chars = s.toCharArray();

        for (int i = 0; i < 4; i++) {
            char old = chars[i];

            // rotate up
            chars[i] = (old == '9') ? '0' : (char)(old + 1);
            res.add(new String(chars));

            // rotate down
            chars[i] = (old == '0') ? '9' : (char)(old - 1);
            res.add(new String(chars));

            chars[i] = old;
        }

        return res;
    }
}