class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        const int linf = 2e9;

        auto check = [&](vector<vector<pair<int,int>>>& adj) {
            vector<int> dis(n + 5, linf);
            set<pair<int, int>> s; // cost, node
            s.insert({0, source});
            dis[source] = 0;
            while (!s.empty()) {
                int u = s.begin()->second;
                if (u == destination) {
                    return s.begin()->first;
                }
                s.erase(s.begin());
                for (auto& x : adj[u]) {
                    int v = x.first;
                    int cost = x.second;
                    if (dis[u] + cost < dis[v]) {
                        dis[v] = dis[u] + cost;
                        s.insert({dis[v], v});
                    }
                }
            }
            return linf;
        };

        vector<vector<pair<int, int>>> adj(n + 5);
        for (auto& i : edges) {
            int u = i[0], v = i[1], w = i[2];
            if (w != -1) {
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
            }
        }
        vector<vector<int>> ans;
        if (check(adj) < target) return ans;
        bool noNeg = true;
        for (auto& i : edges) {
            if (i[2] == -1) {
                noNeg = false;
                i[2] = 1;
                adj[i[0]].push_back({i[1], i[2]}); 
                adj[i[1]].push_back({i[0], i[2]}); 
                int temp = check(adj);
                if (temp != linf && temp <= target) {
                    i[2] += target - temp;
                    for (auto& x : edges) {
                        if(x[2] == -1) x[2] = linf;
                        ans.push_back(x);
                    }
                    return ans;
                } 
            }
        }
        if (noNeg) {
            int temp = check(adj);
                if (temp != linf && temp <= target) {
                    for (auto& x : edges) {
                        ans.push_back(x);
                    }
                } 
        }
        return ans;
    }
};