class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int mx = 0;
        int n = candidates.size();
        for (int bit = 0; bit < 30; bit++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if ((1 << bit) & candidates[i]) {
                    cnt++;
                }
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};