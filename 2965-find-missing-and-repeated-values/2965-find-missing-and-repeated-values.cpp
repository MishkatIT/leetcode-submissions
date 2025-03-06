class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int both = 0;
        int n = grid[0].size();
        for (auto& i : grid) {
            for (auto& j : i) {
                both ^= j;
            }
        }
        for (int i = 1; i <= n * n; i++) {
            both ^= i;
        }
        int groupA = 0, groupB = 0;
        int lsb = both & -both;
        for (auto& i : grid) {
            for (auto& j : i) {
                if (j & lsb) groupA ^= j;
                else groupB ^= j;
            }
        }
        for (int i = 1; i <= n * n; i++) {
            if (i & lsb) groupA ^= i;
            else groupB ^= i;
        }
        
        for (auto& i : grid) {
            for (auto& j : i) {
                if (j == groupA) {
                    return {groupA, groupB};
                }
            }
        }
        return {groupB, groupA};
    }
};