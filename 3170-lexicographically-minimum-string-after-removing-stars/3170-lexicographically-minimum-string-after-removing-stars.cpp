class Solution {
public:
    string clearStars(string s) {
        map<int, vector<int>> mp;
        int n = s.size();
        vector<bool> notTake(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                notTake[i] = true;
                notTake[mp.begin()->second.back()] = true;
                mp.begin()->second.pop_back();
                if (mp.begin()->second.size() == 0) {
                    mp.erase(mp.begin()->first);
                }
            } else {
                mp[s[i]].push_back(i);
            }
        }
        string ans;
        for (int i = 0; i < n; i++) {
            if (notTake[i]) continue;
            ans += s[i];
        }
        return ans;
    }
};