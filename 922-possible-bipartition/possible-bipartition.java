class Solution {
    public boolean possibleBipartition(int n, int[][] dislikes) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] dislike : dislikes) {
            graph.get(dislike[0]).add(dislike[1]);
            graph.get(dislike[1]).add(dislike[0]);
        }

        int[] color = new int[n + 1]; // -1: blue, 1: red
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0 && !dfs(i, graph, color, 1)) return false;
        }

        return true;
    }

    private boolean dfs(int cur, List<List<Integer>> graph, int[] color, int curColor) {
        color[cur] = curColor;

        for (int i : graph.get(cur)) {
            if (color[cur] == color[i]) return false;
            if (color[i] == 0 && !dfs(i, graph, color, -curColor)) return false;
        }

        return true;
    }
}