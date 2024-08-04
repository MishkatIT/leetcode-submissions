class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> all;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                all.push_back(sum);
            }
        }
        sort(all.begin(), all.end());
        int ans = 0;
        --right,--left;
        while (left <= right) {
            ans += all[left++];
            ans %= (int)1e9 + 7;
        }
        return ans;
    }
};