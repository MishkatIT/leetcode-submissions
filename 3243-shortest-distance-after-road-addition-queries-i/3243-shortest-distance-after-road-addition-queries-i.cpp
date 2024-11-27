class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }


        auto bfs = [&]() -> int {
            vector<int>dis(n, 1e9);
            dis[0] = 0;
            set<pair<int, int>> s; // weight, node
            s.insert({0, 0});
            while (!s.empty()) {
                int u = s.begin()->second;
                s.erase(s.begin());
                for (auto& v : adj[u]) {
                    if (dis[u] + 1 < dis[v]) {
                        s.erase({dis[v], v});
                        dis[v] = dis[u] + 1;
                        s.insert({dis[v], v});
                    }
                }
            }
            return dis[n - 1];
        };

        vector<int> ans;
        for (auto& i : queries) {
            adj[i[0]].push_back(i[1]);
            ans.push_back(bfs());
        }
        return ans;
    }
};