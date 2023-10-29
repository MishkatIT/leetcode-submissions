class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i + 1;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int rem = target - nums[i];
            if(mp[rem] && mp[rem] - 1 != i) {
                ans.push_back(i);
                ans.push_back(mp[rem] - 1);
                break;
            }
        }
        return ans;
    }
};