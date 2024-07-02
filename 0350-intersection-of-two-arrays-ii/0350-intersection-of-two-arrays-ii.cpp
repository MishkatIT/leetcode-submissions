class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> f(1001);
        for (auto& i : nums1) {
            f[i]++;
        }
        vector<int> ans;
        for (auto& i : nums2) {
            if (f[i]) {
                ans.push_back(i);
                f[i]--;
            }
        }
        return ans;
    }
};