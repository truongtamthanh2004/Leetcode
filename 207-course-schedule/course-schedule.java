class Solution {
    List<List<Integer>> cons = new ArrayList<>();
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            cons.add(new ArrayList<>());
        }
        int[] inDegree = new int[numCourses];
        for (int[] u : prerequisites) {
            cons.get(u[1]).add(u[0]);
            inDegree[u[0]]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.offer(i);
        }

        int idx = 0;
        while (!q.isEmpty()) {
            int cur = q.poll();
            idx++;

            for (int u : cons.get(cur)) {
                inDegree[u]--;

                if (inDegree[u] == 0) q.offer(u);
            }
        }

        return idx == numCourses;
    }
}