class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int ans = 0;
        int cur = *s.begin();
        int len = 0;
        for (auto& i : s) {
            if (cur == i) {
                cur++;
                len++;
                ans = max(ans, len);
            } else {
                cur = i;
                len = 1;
            }
        }
        return ans;
    }
};