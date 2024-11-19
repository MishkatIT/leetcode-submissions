class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        map<int, int> mp;
        long long sum = 0;
        for (int l = 0, r = 0; r < n; r++) {
            sum += nums[r];
            mp[nums[r]]++;
            if (r >= k - 1) {
                if (mp.size() == k) {
                    ans = max(ans, sum);
                }
                sum -= nums[l];
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
        }
        return ans;
    }
};