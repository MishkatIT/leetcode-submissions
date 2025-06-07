class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> f(26);
        int n = s.size();
        vector<bool> removed(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                removed[i] = true;
                for (int j = 0; j < 26; j++) {
                    if (!f[j].empty()) {
                        removed[f[j].back()] = true;
                        f[j].pop_back();
                        break;
                    }
                }
            } else {
                f[s[i] - 'a'].push_back(i);
            }
        }
        string ans;
        for (int i = 0; i < n; i++) {
            if (removed[i]) continue;
            ans += s[i];
        }
        return ans;
    }
};