class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 5);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int root(int x) {
        return(parent[x] == x ? x : parent[x] = root(parent[x]));
    }

    void join(int x, int y) {
        x = root(x);
        y = root(y);
        if (x < y) parent[y] = x;
        else parent[x] = y;
        return;
    }

};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        DSU dsu(26);
        for (int i = 0; i < n; i++) {
            dsu.join(s1[i] - 'a', s2[i] - 'a');
        }
        for (auto& i : baseStr) {
            i = char(dsu.root(i - 'a') + 'a');
        }
        return baseStr;
    }
};