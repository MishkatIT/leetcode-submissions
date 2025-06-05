class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        map<char, set<char>> mp;
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            mp[s1[i]].insert(s2[i]);
            mp[s2[i]].insert(s1[i]);
        }
        map<char, bool> vis;
        set<char> temp;
        function<void(char)> dfs = [&](char c) {
            temp.insert(c);
            vis[c] = true;
            for (auto& j : mp[c]) {
                if (!vis[j]) {
                    dfs(j);
                }
            }
        };
        map<char, char> p;
        for (char c = 'a'; c <= 'z'; c++) {
            if (!vis[c]) {
                temp.clear();
                dfs(c);
                int x = *temp.begin();
                temp.erase(temp.begin());
                p[x] = x;
                for (auto& i : temp) {
                    p[i] = x;
                }
            }
        }
        for (auto& i : baseStr) {
            i = p[i];
        }
        return baseStr;
    }
};