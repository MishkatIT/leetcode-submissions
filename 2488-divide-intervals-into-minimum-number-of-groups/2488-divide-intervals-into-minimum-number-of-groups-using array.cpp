class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> diff(1e6 + 6);
        for (auto& i : intervals) {
            diff[i[0]]++;
            diff[i[1] + 1]--;
        }
        for (int i = 1; i < (int)1e6 + 5; i++) {
            diff[i] += diff[i - 1];
        }
        return *max_element(diff.begin(), diff.end());
    }
};