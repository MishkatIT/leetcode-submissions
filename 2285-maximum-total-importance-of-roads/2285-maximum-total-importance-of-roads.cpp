class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int, int> mp;
        for (auto& i : roads) {
            mp[i[0]]++;
            mp[i[1]]++;
        }
        vector<int> temp;
        for (auto& i : mp) {
            temp.push_back(i.second);
        }
        sort(temp.rbegin(), temp.rend());
        long long ans = 0;
        long long cur = n;
        for (auto& i : temp) {
            ans += cur * i;
            cur--;
        }
        return ans;
    }
};