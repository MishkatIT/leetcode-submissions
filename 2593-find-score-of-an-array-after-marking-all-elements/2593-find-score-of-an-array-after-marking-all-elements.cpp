class Solution {
public:
    long long findScore(vector<int>& nums) {
        map<int, bool> vis;
        vector<pair<int, int>> srt;
        for (int i = 0; i < nums.size(); i++) {
            srt.push_back({nums[i], i});
        }
        sort(srt.begin(), srt.end());
        long long ans = 0;
        for (int i = 0; i < srt.size(); i++) {
            if (!vis[srt[i].second]) {
                ans += srt[i].first;
                vis[srt[i].second] = true;
                vis[srt[i].second - 1] = true;
                vis[srt[i].second + 1] = true;
            }
        }
        return ans;
    }
};