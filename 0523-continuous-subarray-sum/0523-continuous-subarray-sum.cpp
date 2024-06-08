class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = -1;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int x = sum % k;
            if (!mp.count(x)) {
                mp[x] = i;
            } else {
                if (i - mp[x] > 1) {
                    return true;
                }
            }
        }
        return false;
    }
};