class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // vector<vector<int>> list(n);
        // for (int i = 0; i < edges.size(); i++)
        // {
        //     list[edges[i][0]].push_back[edges[i][1]];
        //     list[edges[i][1]].push_back[edges[i][0]];
        // }

        // vector<bool> visited(n, false);
        // visited[source] = true;

        // stack<int> s;
        // for (auto i : edges)
        // {
        //     int x = i[0];
        // }

        unordered_map<int, vector<int>> graph;
        
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        queue<int> queue;
        unordered_set<int> visited;
        
        queue.push(source);
        visited.insert(source);
        
        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            if (node == destination) {
                return true;
            }
            for (int neighbor : graph[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    queue.push(neighbor);
                }
            }
        }
        
        return false;
    }
};