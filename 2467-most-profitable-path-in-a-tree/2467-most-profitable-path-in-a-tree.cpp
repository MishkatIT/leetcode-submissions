class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> g(n);

        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> dist(n, -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        vector<int> distBob(n, -1);
        int cur = bob, d = 0;
        while (cur != -1) {
            distBob[cur] = d++;
            if (cur == 0) {
                cur = -1;
            } else {
                auto it = find_if(g[cur].begin(), g[cur].end(), [&](int v) {
                    return dist[v] < dist[cur];
                });
                if (it != g[cur].end()) {
                    cur = *it;
                } else {
                    cur = -1;
                }
            }
        }

        function<int(int, int)> dfs = [&](int u, int par) {
            int gain = amount[u];
            if (distBob[u] != -1) {
                if (dist[u] < distBob[u])
                    gain = amount[u];
                else if (dist[u] == distBob[u])
                    gain = amount[u] / 2;
                else
                    gain = 0;
            }
            int maxGain = INT_MIN;
            for (int v : g[u]) {
                if (v != par)
                    maxGain = max(maxGain, dfs(v, u));
            }
            return gain + (maxGain == INT_MIN ? 0 : maxGain);
        };

        return dfs(0, -1);
    }
};