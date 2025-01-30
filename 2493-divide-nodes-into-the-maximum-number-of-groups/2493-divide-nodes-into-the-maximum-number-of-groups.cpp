class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> adj[n + 5];
        for (auto& i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        auto isBipartite = [&]() {
            vector<int> color(n + 5, -1);
            for (int i = 1; i <= n; i++) {
                if (color[i] == -1) {
                    queue<int> q;
                    q.push(i);
                    color[i] = 0;
                    while (!q.empty()) {
                        int u = q.front();
                        q.pop();
                        for (auto& v : adj[u]) {
                            if (color[v] == -1) {
                                color[v] = !color[u];
                                q.push(v);
                            } else if (color[u] == color[v]) return false;
                        }
                    }
                }
            }
            return true;
        };

        if (!isBipartite()) return -1;  

        vector<bool> vis(n + 5);

        auto bfs = [&](int u) {
            queue<int> q;
            q.push(u);
            vector<int> temp;
            temp.push_back(u);
            vis[u] = true;
            while (!q.empty()) {
                u = q.front();
                q.pop();
                for (auto& v : adj[u]) {
                    if (!vis[v]) {
                            vis[v] = true;
                            temp.push_back(v);
                            q.push(v);
                        }
                    }
            }
            int mx = 1;
            for (auto& start : temp) {
                vector<bool> taken(n + 5);
                queue<array<int, 2>> q;
                q.push({start, 1});
                taken[start] = true;
                while (!q.empty()) {
                    int u = q.front()[0];
                    int x = q.front()[1];
                    mx = max(mx, x);
                    q.pop();
                    for (auto& v : adj[u]) {
                        if (!taken[v]) {
                            taken[v] = true;
                            q.push({v, x + 1});
                        }
                    }
                }
            }
            return mx;
        };


        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                ans += bfs(i);
            }
        }
        return ans;
    }
};