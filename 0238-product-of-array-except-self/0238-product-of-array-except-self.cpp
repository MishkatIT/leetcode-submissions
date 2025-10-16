class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n, 1), s(n, 1);
        p.front() = nums.front();
        s.back() = nums.back();
        for (int i = 1; i < n; i++) {
            p[i] *= p[i - 1] * nums[i];
        }
        for (int i = n - 2; i >=0; i--) {
            s[i] *= s[i + 1] * nums[i];
        }
        vector<int> ans(n, 1);
        ans.front() = s[1];
        ans.back() = p[n - 2];
        for (int i = 1; i < n - 1; i++) {
            ans[i] = p[i - 1] * s[i + 1];
        }
        return ans;
    }
};