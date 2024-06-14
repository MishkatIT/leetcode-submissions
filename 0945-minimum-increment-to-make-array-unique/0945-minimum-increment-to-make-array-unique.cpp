class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> f(1e5 + 5);
        for (auto& i : nums) {
            f[i]++;
        }
        long long ans = 0;
        for (int i = 0; i <= 1e5; i++) {
            if (f[i] > 1) {
                ans += f[i] - 1;
                f[i + 1] += f[i] - 1;
            }
        }
        long long x = f[1e5 + 1];
        x--;
        ans += x * (x + 1) / 2;
        return ans;
    }
};