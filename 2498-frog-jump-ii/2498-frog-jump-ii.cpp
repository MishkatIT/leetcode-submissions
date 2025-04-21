class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int ans = stones[1];
        for (int i = 0; i + 2 < n; i += 2) {
            ans = max(ans, stones[i + 2] - stones[i]);
        }
        for (int i = 1; i + 2 < n; i += 2) {
            ans = max(ans, stones[i + 2] - stones[i]);
        }
        return ans;
    }
};