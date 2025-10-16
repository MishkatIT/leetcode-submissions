class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (mp.count(need)) {
                return {i, mp[need]};
            }
            mp[nums[i]] = i;
        }
        return {0, 0};
    }
};