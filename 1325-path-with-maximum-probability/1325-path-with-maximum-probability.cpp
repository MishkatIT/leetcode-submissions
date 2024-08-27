class Solutio {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& suc , int st, int en) {
        for (auto& i : suc) i = log(i);
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], suc[i]});
            adj[edges[i][1]].push_back({edges[i][0], suc[i]});
        }

        set<pair<double, int>, greater<pair<double, int>>> s; // weight, node
        s.insert({0, st});
        vector<double> dis(n, -1e9);
        while (!s.empty()) {
            int u = s.begin()->second;
            s.erase(s.begin());
            for (auto& x : adj[u]) {
                int v = x.first;
                double cost = x.second;
                if (dis[u] + cost > dis[v]) {
                    dis[v] = dis[u] + cost;
                    s.insert({dis[v], v});
                }
            }
        }
    return exp(dis[en]);
        return 0;
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& suc , int st, int en) {
        for (auto& i : suc) i = log(i);
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], suc[i]});
            adj[edges[i][1]].push_back({edges[i][0], suc[i]});
        }

        set<pair<double, int>, greater<pair<double, int>>> s; // weight, node
        s.insert({0, st});
        vector<double> dis(n, -1000000000);
        while (!s.empty()) {
            int u = s.begin()->second;
            double w = s.begin()->first;
            s.erase(s.begin());
            for (auto& x : adj[u]) {
                int v = x.first;
                double cost = x.second;
                if (w + cost > dis[v]) {
                    dis[v] = w + cost;
                    s.insert({dis[v], v});
                }
            }
        }
        for (auto& i : dis) cout << i << ' ';
        return exp(dis[en]);
    }
};