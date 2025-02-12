class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int, vector<int>> mp;
        for (auto& i : nums) {
            int x = i;
            int sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            mp[sum].push_back(i);
        }
        int ans = -1;
        for (auto& i : mp) {
            int sz = i.second.size();
            if (sz > 1) {
                sort(i.second.begin(), i.second.end());
                ans = max(ans, i.second[sz - 1] + i.second[sz - 2]);
            }
        }
        return ans;
    }
};