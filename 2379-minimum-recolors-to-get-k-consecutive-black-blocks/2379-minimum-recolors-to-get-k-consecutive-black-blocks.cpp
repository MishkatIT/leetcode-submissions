class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int white = 0;
        int n = blocks.size();
        int ans = k;
        for (int i = 0; i < n; i++) {
            white += (blocks[i] == 'W');
            if (i >= k - 1) {
                ans = min(ans, white);
                white -= (blocks[i - k + 1] == 'W');
            }
        }
        return ans;
    }
};