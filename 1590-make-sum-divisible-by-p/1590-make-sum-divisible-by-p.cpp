class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        using ll = long long;
        ll tot = 0;
        for (auto& i : nums) tot += i;
        int rem = tot % p;
        if (rem == 0) return 0;
        cout << rem;
        map<ll, int> have; // sum, pos
        have[0] = -1;
        ll pref = 0;
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            pref += nums[i];
            int need = (pref % p - rem + p) % p;
            if (have.find(need) != have.end()) {
                ans = min(ans, i - have[need]); 
            }
            have[pref % p] = i;
        }
        return ans == nums.size() ? -1 : ans;
    }
};