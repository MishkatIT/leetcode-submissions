class Solution {
public:
    void rotate(vector<vector<int>>& v) {
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(v[i][j], v[j][i]);
            }
        }
         for (int i = 0; i < n; i++)
        {
            reverse(v[i].begin(), v[i].end());
        }
    }
};