class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = 1e9;
        int ans = 0;
        for (auto& i : prices) {
            ans = max(ans, i - mn);
            mn = min(mn, i);
        }
        return ans;
    }
};