class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool ok = true;
        for (int i = 0; i + 1 < nums.size(); i++) {
            ok &= (nums[i] % 2 != nums[i + 1] % 2);
        }
        return ok;
    }
};