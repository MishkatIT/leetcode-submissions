class Solution {
public:
    int minimumPushes(string word) {
        map<char, int> mp;
        for (auto& i : word) {
            mp[i]++;
        }
        vector<int> temp;
        for (auto& i : mp) {
            temp.push_back(i.second);
        }
        sort(temp.rbegin(), temp.rend());
        int cnt = 0;
        int ans = 0;
        int seg = 1;
        for (auto& i : temp) {
            cnt++;
            ans += i * seg;
            if (cnt == 8) {
                seg++;
                cnt = 0;
            }
        }
        return ans;
    }
};