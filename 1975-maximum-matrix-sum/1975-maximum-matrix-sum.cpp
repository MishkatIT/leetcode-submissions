class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int mn = 1e9;
        bool odd = 0;
        for (auto& i : matrix) {
            for (auto& j : i) {
                sum += abs(j);
                mn = min(mn, abs(j));
                if (j < 0) odd ^= 1;
            }
        }
        return (odd ? sum - mn * 2 : sum);
    }
};