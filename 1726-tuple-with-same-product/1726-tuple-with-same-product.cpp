class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int, int> mp;
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x = nums[i] * nums[j];
                mp[x]++;
                ans += mp[x] - 1;
            }
        }
        return ans * 8;
    }
};