class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> temp;

        auto getInt = [&](char c) {
            return c - '0';
        };

        for (auto& i: timePoints) {
            int x = 60 * (getInt(i[0]) * 10 + getInt(i[1])) + getInt(i[3]) *  10 + getInt(i[4]);
            temp.push_back(x);
        }
        sort(temp.begin(), temp.end());
        int n = timePoints.size();
        int ans = temp[n - 1];
        for (int i = 0; i + 1 < n; i++) {
            ans = min({ans, temp[i + 1] - temp[i], 1440 - temp[i + 1] + temp[i]});
        }
        if (n > 1) {
            ans = min (ans, 1440 -  temp[n - 1] + temp[0]);
        }
        return ans;
    }
};