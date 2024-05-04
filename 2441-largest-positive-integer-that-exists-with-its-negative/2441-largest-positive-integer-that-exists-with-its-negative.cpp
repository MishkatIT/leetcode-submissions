class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int, bool> mp;
        for (auto& i : nums) {
            mp[i] = true;
        }
        int ans = -1;
        for (auto& i : mp) {
            if (mp.find(-i.first) != mp.end()) {
                ans = abs(i.first);
                break;
            }
        }
        return ans;
    }
};