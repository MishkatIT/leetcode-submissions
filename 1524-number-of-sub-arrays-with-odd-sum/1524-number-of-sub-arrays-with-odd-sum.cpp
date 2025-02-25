class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;
        int even = 0, odd = 0;
        int sum = 0;
        int mod = 1e9 + 7;
        for (auto& i : arr) {
            sum += i;
            if (sum & 1) {
                ans = (1 + ans + even) % mod;
                odd++;
            } else {
                ans = (ans + odd) % mod;
                even++;
            }
        }
        return ans;
    }
};