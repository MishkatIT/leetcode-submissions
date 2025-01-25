class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<array<int, 2>> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = {nums[i], i};
        }
        sort(temp.begin(), temp.end());
        for (int i = 0; i < n; i++) cout << temp[i][0] << ' ';
        vector<array<int, 2>> cur;
        cur.push_back(temp.front());
        vector<int> ans(n);
        for (int i = 1; i < n; i++) {
            if (temp[i][0] - cur.back()[0] > limit) {
                vector<int> pos;
                for (auto& x : cur) pos.push_back(x[1]);
                sort(pos.begin(), pos.end());
                for (int x = 0; x < pos.size(); x++) {
                    ans[pos[x]] = cur[x][0];
                }
                cur.clear();
            }
            cur.push_back(temp[i]);
        }
        vector<int> pos;
        for (auto& x : cur) pos.push_back(x[1]);
        sort(pos.begin(), pos.end());
        for (int x = 0; x < pos.size(); x++) {
            ans[pos[x]] = cur[x][0];
        }
        return ans;
    }
};