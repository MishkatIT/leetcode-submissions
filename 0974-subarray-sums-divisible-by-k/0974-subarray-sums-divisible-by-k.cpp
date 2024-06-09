class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        long long pref = 0, ans = 0;
        map<long long, long long> mp;
        mp[0] = 1;
        for (auto& i : nums) {
            pref += i;
            pref %= k;
            pref = (pref + k) % k;
            ans += mp[pref];
            mp[pref]++;
        }
        return ans;
    }
};