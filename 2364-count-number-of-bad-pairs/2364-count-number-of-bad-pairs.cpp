class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        using ll = long long;
        ll n = nums.size();
        ll ans = n * (n + 1) / 2 ;
        map<ll, ll> mp;
        for (int i = 0; i < n; i++) {
            ans -= mp[nums[i] - i] + 1;
            mp[nums[i] - i]++;
        }
        return ans;
    }
};