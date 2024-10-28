class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int, bool> mp;
        for (auto& i : nums) {
            mp[i] = true;
        }
        int ans = -1;
        for (auto& i : nums) {
            long long cur = i;
            int cnt = 0;
            cur *= cur;
            while (cur <= 1e5 && mp[cur]) {
                cnt += mp[cur];
                cur *= cur;
            }
            ans = max(ans, cnt + (cnt > 0));
        }
        return ans == 0 ? -1 : ans;
    }
};