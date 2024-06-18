class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {profit[i], difficulty[i]};
        }
        sort(v.rbegin(), v.rend());
        multiset<int> ms;
        for (auto& i : worker) {
            ms.insert(i);
        }
        int ans = 0;
        for (int i = 0; i < n;) {
            auto it = ms.lower_bound(v[i].second);
            if (it == ms.end()) {
                i++;
                continue;
            } 
            ans += v[i].first;
            ms.erase(it);
        }
        return ans;
    }
};