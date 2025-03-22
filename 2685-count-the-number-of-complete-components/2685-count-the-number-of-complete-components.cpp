class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& e) {
        vector<vector<int>> g(n);
        map<string, int> mp;
        for (int i = 0; i < n; i++) g[i].push_back(i);
        for (auto& i : e) g[i[0]].push_back(i[1]), g[i[1]].push_back(i[0]);
        for (int i = 0; i < n; i++) {
            vector<int> v = g[i];
            sort(v.begin(), v.end());
            string str;
            for (int j : v) str += to_string(j) + ",";
            mp[str]++;
        }
        int ans = 0;
        for (auto& i : mp) if (count(i.first.begin(), i.first.end(), ',') == i.second) ans++;
        return ans;
    }
};
