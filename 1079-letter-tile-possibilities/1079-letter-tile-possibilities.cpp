class Solution {
public:
    int cnt = 0;
    map<char, int> mp;
    void dfs() { 
        for (auto& i : mp) {
            if (i.second > 0) {
                i.second--;
                cnt += 1;
                dfs();
                i.second++;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        for (auto& i : tiles) {
            mp[i]++;
        }
        dfs();
        return cnt;
    }
};