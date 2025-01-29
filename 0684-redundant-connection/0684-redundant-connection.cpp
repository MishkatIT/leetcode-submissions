class DSU {
public:
    vector<int> parent, child;
    DSU (int n){
        parent.resize(n + 5);
        iota(parent.begin(), parent.end(), 0);
        child.resize(n + 5, 1);
    }

    int root(int x) {
        return parent[x] == x ? x : parent[x] = root(parent[x]);
    }

    bool join(int u, int v) {
        u = root(u), v = root(v);
        if (u != v) {
            if (child[u] < child[v]) swap(u, v);
            parent[v] = parent[u];
            child[u] += child[v];
            return true;
        }
        return false;
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        DSU dsu(edges.size());
        for (auto& i : edges) {
            if (!dsu.join(i[0], i[1])) ans = {i[0], i[1]};
        }
        return ans;
    }
};