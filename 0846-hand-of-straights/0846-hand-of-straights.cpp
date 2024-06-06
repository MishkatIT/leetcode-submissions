class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if ((int)hand.size() % groupSize != 0) return false;
        map<int, int> mp;
        for (auto& i : hand) {
            mp[i]++;
        }
        bool ok = true;
        for (auto& i : mp) {
            if (i.second) {
                int cnt = groupSize - 1;
                int cur = i.first + 1;
                while (cnt--) {
                    if (mp[cur] >= i.second) {
                        mp[cur] -= i.second;
                    } else {
                        ok = false;
                        break;
                    }
                    cur++;
                }
                if (!ok) break;
            }
        }
        return ok;

    }
};