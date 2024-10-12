class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> diff;
        for (auto& i : intervals) {
            diff[i[0]]++;
            diff[i[1] + 1]--;
        }
        int cur = 0;
        int mx = 0;
        for (auto& i : diff) {
            i.second += cur;
            cur = i.second;
            mx = max(cur, mx);
        }
        return mx;
    }
};