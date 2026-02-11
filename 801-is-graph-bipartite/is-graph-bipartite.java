class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        // 1: Red, -1: Blue
        int[] color = new int[n];

        for (int i = 0; i < n; i++) {
            if (color[i] == 0 && !dfs(i, graph, color, 1)) return false;
        }

        return true;
    }

    private boolean dfs(int cur, int[][] graph, int[] color, int curColor) {
        color[cur] = curColor;

        for (int i : graph[cur]) {
            if (color[i] == color[cur]) return false;

            if (color[i] == 0 && !dfs(i, graph, color, -curColor)) return false;
        }

        return true;
    }
}