class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        map<int, int> mp, cnt;
        int n = queries.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int pos = queries[i][0];
            int col = queries[i][1];
            if(mp.count(pos)) {
                cnt[mp[pos]]--;
                if (cnt[mp[pos]] == 0) {
                    cnt.erase(mp[pos]);
                }
            }
            mp[pos] = col;
            cnt[col]++;
            ans[i] = cnt.size();
        }
        return ans;
    }
};