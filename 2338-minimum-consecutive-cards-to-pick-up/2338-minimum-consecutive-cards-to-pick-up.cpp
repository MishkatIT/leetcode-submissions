class Solution {
public:
    int minimumCardPickup(vector<int>& v) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        for (int i = 0; i < (int)v.size(); i++)
        {
            if(mp[v[i]])
                ans = min(ans, abs(mp[v[i]] - i) + 2);
            mp[v[i]] = i + 1;
        }
        if(ans == INT_MAX)
            ans = -1;
        return ans;
    }
};