class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates
            
            unordered_set<int> seen;
            for (int j = i + 1; j < n; j++) {
                int need = -nums[i] - nums[j];
                if (seen.count(need)) {
                    ans.push_back({nums[i], nums[j], need});
                    while (j + 1 < n && nums[j] == nums[j + 1]) j++; // skip duplicates
                }
                seen.insert(nums[j]);
            }
        }
        
        return ans;
    }
};
