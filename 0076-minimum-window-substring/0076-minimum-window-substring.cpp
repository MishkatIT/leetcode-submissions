class Solution {
public:
    string minWindow(string s, string t) {
        multiset<char> x(t.begin(), t.end());
        map<char, int> boss;
        for (auto& i : t) {
            boss[i]++;
        }
        int n = s.size();
        int len = 1e9;
        map<char, int> cur;
        int start = 0;
        for (int l = 0, r = 0; r < n; r++) {
            cur[s[r]]++;
            auto it = x.find(s[r]);
            if (it != x.end()) {
                x.erase(it);
            }
            if (x.empty()) {
                while (cur[s[l]] > boss[s[l]]) {
                    cur[s[l]]--;
                    l++;
                }
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    start = l;
                }
            }
        }
        if (len == 1e9) return "";
        return (s.substr(start, len));
    }
};