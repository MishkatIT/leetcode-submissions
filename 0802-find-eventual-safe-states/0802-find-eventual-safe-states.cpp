class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n);
        vector<int> good(n);
        function<int(int)> dfs = [&](int i) -> int {
            vis[i] = true;
            bool ok = true;
            for (auto& j : graph[i]) {
                if (!vis[j]) ok &= dfs(j); 
                else ok &= (graph[j].size() == 0 || good[j]);
            }
            return good[i] = ok;
        };

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (good[i]) ans.push_back(i);
        }
        return ans;
    }
};