class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        map<int, int> mp;
        for (int i = 0; i < (int)score.size(); i++)
            mp[score[i][k]] = i;
        vector<vector<int>> ans;
        for(auto i = mp.rbegin(); i != mp.rend(); i++) {
            ans.push_back(score[i -> second]);
        }
        return ans;
    }
};