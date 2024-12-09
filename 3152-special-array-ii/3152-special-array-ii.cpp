class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pre(n);
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) pre[i]++;
            pre[i] += pre[i - 1];
        }
        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
            if (l == r) ans[i] = true;
            int x = pre[r] - pre[l];
            ans[i] = (x == 0);
        }
        return ans;
    }
};