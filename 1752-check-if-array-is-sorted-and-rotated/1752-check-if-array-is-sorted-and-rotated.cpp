class Solution {
public:
    bool check(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (is_sorted(nums.begin(), nums.end())) return true;
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
        }
        return false;
    }
};