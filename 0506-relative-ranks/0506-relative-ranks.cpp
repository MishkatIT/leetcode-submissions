class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp = score;
        sort(temp.rbegin(), temp.rend());
        int n = score.size();
        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            if (score[i] == temp[0]) {
                ans[i] = "Gold Medal";
            } else if (score[i] == temp[1]) {
                ans[i] = "Silver Medal";
            } else if (score[i] == temp[2]) {
                ans[i] = "Bronze Medal";
            } else {
                ans[i] = to_string(find(temp.begin(), temp.end(), score[i]) -
                                   temp.begin() + 1);
            }
        }
        return ans;
    }
};