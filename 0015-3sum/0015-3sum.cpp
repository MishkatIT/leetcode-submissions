class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (l >= r) break;
                if (nums[i] + nums[l] + nums[r] > 0) {
                    r--;
                }
                else if (nums[i] + nums[l] + nums[r] < 0) {
                    l++;
                } else {
                    s.insert({nums[i], nums[l], nums[r]});
                    l++, r--;
                }
            }
        }
        
        vector<vector<int>> ans;
        for (auto& i: s) {
            ans.push_back(i);
        }
        return ans;
    }
};