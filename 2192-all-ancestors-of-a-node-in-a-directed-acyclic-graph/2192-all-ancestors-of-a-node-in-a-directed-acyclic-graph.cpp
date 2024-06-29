class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        vector<set<int>> anc(n);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& neighbor : adj[node]) {
                anc[neighbor].insert(node);
                anc[neighbor].insert(anc[node].begin(), anc[node].end());
                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = vector<int>(anc[i].begin(), anc[i].end());
        }

        return ans;
    }
};