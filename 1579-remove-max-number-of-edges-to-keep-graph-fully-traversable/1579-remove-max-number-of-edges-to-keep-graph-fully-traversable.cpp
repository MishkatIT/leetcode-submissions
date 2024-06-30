/*
    Author    : MishkatIT
*/

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> p, r;

    DSU(int n) {
        p.resize(n);
        r.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }

    int root(int x) { return (p[x] != x) ? (p[x] = root(p[x])) : x; }

    bool join(int u, int v) {
        int ru = root(u);
        int rv = root(v);

        if (ru != rv) {
            if (r[ru] < r[rv]) {
                swap(ru, rv);
            }

            p[rv] = ru;
            r[ru] += r[rv];
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsuA(n), dsuB(n);
        int rem = 0, com = 0, a = 0, b = 0;

        for (auto& e : edges) {
            if (e[0] == 3) {
                if (dsuA.join(e[1] - 1, e[2] - 1)) {
                    dsuB.join(e[1] - 1, e[2] - 1);
                    com++;
                } else {
                    rem++;
                }
            }
        }

        for (auto& e : edges) {
            if (e[0] == 1) {
                if (dsuA.join(e[1] - 1, e[2] - 1)) {
                    a++;
                } else {
                    rem++;
                }
            } else if (e[0] == 2) {
                if (dsuB.join(e[1] - 1, e[2] - 1)) {
                    b++;
                } else {
                    rem++;
                }
            }
        }

        bool fullA = (a + com == n - 1);
        bool fullB = (b + com == n - 1);

        if (fullA && fullB) {
            return rem;
        } else {
            return -1;
        }
    }
};
