class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0, pos = 0;
        int n = nums.size();
        int idx = 0;
        while (idx < n && nums[idx] < 0) neg++, idx++;
        while (idx < n && nums[idx] == 0) idx++;
        while (idx < n) pos++, idx++;
        return max(neg, pos);
    }
};