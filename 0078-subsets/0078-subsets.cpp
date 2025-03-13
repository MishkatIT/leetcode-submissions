class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        all (nums, 0);
        return ans;
    }
    vector<vector<int>> ans;
    vector<int> cur;
    void all (vector<int>&v, int i) {
        if (i >= v.size()) {
            ans.push_back(cur);
            return;
        }
        cur.push_back(v[i]);
        all(v, i + 1);
        cur.pop_back();
        all(v, i + 1);
        return;
    }
};