class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int x = 0;
        for (auto& i : nums) x ^= i;
        vector<int> ans;
        int k = (1 << maximumBit) - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans.push_back(k ^ x);
            x ^= nums[i];
        }
        return ans;
    }
};