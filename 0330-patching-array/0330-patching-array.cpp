class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size() && sum < n; i++){
            if (nums[i] <= sum + 1) {
                sum += nums[i];
            } else {
                i--;
                sum += (sum + 1);
                ans++;
            }
        } 
        while (sum < n) {
            sum += (sum + 1);
            ans++;
        }
        return ans;
    }
};