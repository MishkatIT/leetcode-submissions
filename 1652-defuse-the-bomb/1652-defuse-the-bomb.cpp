class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        if (k == 0) return ans;
        for (int i = 0; i < n; i++) {
            int s = 0;
            if (k > 0) {
                for (int j = 1; j <= k; j++) {
                    s += code[(i + j) % n];
                }
            } else {
                for (int j = 1; j <= abs(k); j++) {
                    s += code[(i - j + n) % n];
                }
            }
            ans[i] = s;
        }
        return ans;   
    }
};