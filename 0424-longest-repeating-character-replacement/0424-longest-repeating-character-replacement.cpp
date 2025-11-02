class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0;
        map<char, int> mp;
        int ans = 1;
        while (r < n) {
            mp[s[r]]++;
            while (true) {
                priority_queue<int> pq;
                for (auto& [a, b] : mp) {
                    pq.push(b);
                }
                int bad = r - l + 1 - pq.top();
                if (bad > k) {
                    mp[s[l]]--;
                    if (mp[s[l]] == 0) mp.erase(s[l]);
                    l++;
                } else break;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};