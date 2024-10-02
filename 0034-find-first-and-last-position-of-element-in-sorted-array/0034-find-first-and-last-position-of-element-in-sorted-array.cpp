class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{(int)2e9, (int)2e9};
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                if (ans.front() == 2e9) {
                    ans.front() = i;
                    ans.back() = i;
                } else {
                    ans.back() = i;
                }
            }
        }
        if (ans.back() == 2e9) {
            return {-1, -1};
        } else {
            return ans;
        }
    }
};