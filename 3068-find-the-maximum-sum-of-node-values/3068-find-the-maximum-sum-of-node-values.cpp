class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<int> mx;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mx.push_back((nums[i] ^ k) - nums[i]);
        }
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        sort(mx.rbegin(), mx.rend());
        for (int i = 0; i + 1 < n; i += 2) {
            sum += max(0, mx[i] + mx[i + 1]);
        }
        return sum;
    }
};