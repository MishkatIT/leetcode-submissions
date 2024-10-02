class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s(arr.begin(), arr.end());
        map<int, int> rank;
        int cnt = 0;
        for (auto& i : s) {
            rank[i] = ++cnt;
        }
        vector<int> ans(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = rank[arr[i]];
        }
        return ans;
    }
};