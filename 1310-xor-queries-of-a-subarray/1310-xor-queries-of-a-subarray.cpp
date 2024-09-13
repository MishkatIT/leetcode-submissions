class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> p(n + 5);
        for (int i = 1; i <= n; ++i) {
            p[i] = p[i - 1] ^ arr[i - 1];
        }
        vector<int> ans;
        for (auto& i : queries) {
            ans.push_back(p[i[1] + 1] ^ p[i[0]]);
        }
        return ans;
    }
};