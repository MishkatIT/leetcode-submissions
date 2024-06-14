class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int, int> mp;
        for (auto& i : nums) {
            mp[i]++;
        }
        long long sum = -1;
        long long ans = 0;
        for (auto& i : mp) {
            if (sum < i.first) {
                long long x = i.second - 1;
                ans += x * (x + 1) / 2;
                sum = i.first + x;
            } else {
                long long x = i.second - 1;
                ans += (sum - i.first + 1) * i.second;
                ans += x * (x + 1) / 2;
                sum += i.second;
            }

        }
        return ans;
    }
};