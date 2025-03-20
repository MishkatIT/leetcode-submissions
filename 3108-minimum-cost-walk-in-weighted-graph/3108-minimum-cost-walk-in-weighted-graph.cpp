class Solution {
public:
    vector<int> par, dep;

    vector<int> minimumCost(int n, vector<vector<int>>& edg, vector<vector<int>>& qry) {
        par.resize(n, -1);
        dep.resize(n, 0);
        vector<int> cmpCost(n, -1);

        for (auto& e : edg) {
            Union(e[0], e[1]);
        }

        for (auto& e : edg) {
            int r = find(e[0]);
            cmpCost[r] &= e[2];
        }

        vector<int> ans;
        for (auto& q : qry) {
            int u = q[0], v = q[1];
            if (find(u) != find(v)) ans.push_back(-1);
            else ans.push_back(cmpCost[find(u)]);
        }

        return ans;
    }

private:
    int find(int x) {
        if (par[x] == -1) return x;
        return par[x] = find(par[x]);
    }

    void Union(int x, int y) {
        int r1 = find(x), r2 = find(y);
        if (r1 == r2) return;

        if (dep[r1] < dep[r2]) swap(r1, r2);
        par[r2] = r1;

        if (dep[r1] == dep[r2]) dep[r1]++;
    }
};
