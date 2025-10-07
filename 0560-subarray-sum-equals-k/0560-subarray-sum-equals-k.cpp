class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        map<int, int> mp;
        mp[0] = 1;
        int p = 0;
        for (auto& i : nums) {
            p += i;
            int dif = p - k;
            ans += mp[dif];
            mp[p]++;
        }
        return ans;
    }
};