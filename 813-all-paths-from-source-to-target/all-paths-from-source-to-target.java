class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        int n = graph.length;
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        path.add(0);

        dfs(0, graph, path, ans);

        return ans;
    }

    private void dfs(int cur, int[][] graph, List<Integer> path, List<List<Integer>> ans) {
        if (cur == graph.length - 1) {
            ans.add(new ArrayList<>(path));
            return;
        }

        for (int i : graph[cur]) {
            path.add(i);
            dfs(i, graph, path, ans);
            path.remove(path.size() - 1);
        }
    }
}