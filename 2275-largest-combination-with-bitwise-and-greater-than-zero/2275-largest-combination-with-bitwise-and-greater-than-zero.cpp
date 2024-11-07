class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int mx = 0;
        for (int j = 0; j < 25; j++) {
            int cnt = 0;
            for (int i = 0; i < candidates.size(); i++) {
                if ((1 << j) & candidates[i]) cnt++;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};