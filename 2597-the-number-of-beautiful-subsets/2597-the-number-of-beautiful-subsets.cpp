class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < (1 << n); i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                if ((1 << j) & i) {
                    temp.push_back(nums[j]);
                }
            }
            map<int, bool> mp;
            bool ok = true;
            for (auto& x: temp) {
                ok &= (mp.find(x + k) == mp.end());
                ok &= (mp.find(x - k) == mp.end());
                mp[x] = true; 
            }
            ans += ok;
        }
        return ans;
    }
};