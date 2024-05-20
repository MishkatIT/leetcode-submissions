class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int x = 0;
        for (auto& i : nums) x |= i;
        return x << nums.size() - 1;
    }
};