
class DSU {
public:
    int n = 4e4 + 5;
    vector<int> parent, child;
    DSU() {
        parent.resize(n);
        child.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int root(int x) {
        return ((parent[x] == x) ? x : parent[x] = root(parent[x]));
    }
    bool join(int u, int v) {
        u = root(u);
        v = root(v);
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
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;
        int x = 1e4 + 5;
        int ans = 0;
        for (int i = 0; i < stones.size(); i++) {
            dsu.join(stones[i][0], stones[i][1] + x);
        }
        set<int> con; // connected 
        for (auto& i : stones) {
            con.insert(dsu.root(i[0]));
        }
        return stones.size() - con.size();
    }
};