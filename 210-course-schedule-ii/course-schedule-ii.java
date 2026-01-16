class Solution {
    List<List<Integer>> cons = new ArrayList<>();
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            cons.add(new ArrayList<>());
        }
        int[] inDegree = new int[numCourses];

        for (int[] e : prerequisites) {
            cons.get(e[1]).add(e[0]);
            inDegree[e[0]]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.offer(i);
        }

        int[] res = new int[numCourses];
        int idx = 0;
        while (!q.isEmpty()) {
            int cur = q.poll();
            res[idx++] = cur;

            // Go through neighbor
            for (int u : cons.get(cur)) {
                inDegree[u]--;

                if (inDegree[u] == 0) q.offer(u);
            }
        }

        if (idx < numCourses) return new int[0];

        return res;
    }
}