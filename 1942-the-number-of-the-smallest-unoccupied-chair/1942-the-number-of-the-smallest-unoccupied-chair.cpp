class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        if (times.size() == 1) return 0;
        int cnt = 0;
        int ans = 0;
        vector<array<int, 3>> temp(times.size());
        for (int i = 0; i < times.size(); i++) {
            temp[i][0] = times[i][0];
            temp[i][1] = times[i][1];
            temp[i][2] = i;
        }
        sort(temp.begin(), temp.end());
        set<pair<int, int>> s;
        s.insert({temp[0][0] + temp[0][1], 0});
        int curTime = temp[0][2];
        for (int i = 1; i < times.size(); i++) {
            int st = temp[i][0], en = temp[i][1];
            if (s.begin()->first - curTime <= st) {
                if (temp[i][2] == targetFriend) {
                    ans = s.begin()->second;
                    break;
                }
                s.insert({st + en, s.begin()->second});
                s.erase(s.begin());
            } else {
                cnt++;
                if (temp[i][2] == targetFriend) {
                    ans = cnt;
                    break;
                }
                s.insert({st + en, cnt});
            }
            curTime = st;
        }
        return ans;
    }
};