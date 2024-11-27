class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }


        auto bfs = [&]() -> int {
           queue<pair<int, int>> q; // node, dis
           vector<int> vis(n);
           q.push({0, 0});
           vis[0] = true;
           while (!q.empty()) {
                int u = q.front().first;
                int dis = q.front().second;
                q.pop();
                if (u == n - 1) return dis;
                for (auto& v : adj[u]) {
                    if (!vis[v]) q.push({v, dis + 1});
                    vis[v] = true;
                }
           }
           return n - 1;
        };

        vector<int> ans;
        for (auto& i : queries) {
            adj[i[0]].push_back(i[1]);
            ans.push_back(bfs());
        }
        return ans;
    }
};