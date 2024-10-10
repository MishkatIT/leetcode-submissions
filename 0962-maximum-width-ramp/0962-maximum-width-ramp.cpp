class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        reverse(nums.begin(), nums.end());
        map<int, int> idx;
        vector<int> temp;
        int ans = 0;
        temp.push_back(nums.front());
        idx[nums.front()] = 0;
        for (int i = 1; i < nums.size(); i++) {
            auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
            if (it != temp.end()) {
                ans = max(ans, i - idx[*it]);
            }
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                idx[temp.back()] = i;
            }
        }
        return ans;
    }
};