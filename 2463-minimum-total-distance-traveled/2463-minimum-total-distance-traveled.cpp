class Solution {
public:
    vector<int> fac;
    int n, m; // robot.size, fac.size.
    vector<vector<long long>> dp; 
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        for (int i = 0; i < factory.size(); i++) {
            for (int j = 0; j < factory[i][1]; j++) {
                fac.push_back(factory[i][0]);
            }
        }
        sort(robot.begin(), robot.end());
        sort(fac.begin(), fac.end());
        n = robot.size(), m = fac.size();
        dp.resize(n + 5);
        for (auto& i : dp) {
            i.resize(m + 5, -1);
        }
        return solve(0, 0, robot);
    }

    long long solve(int i, int j, vector<int>& robot) {
        if (i >= n) return 0;
        if (j >= m) return 1e18;
        if (dp[i][j] != -1) return dp[i][j];
        long long take = abs(robot[i] - fac[j]) + solve(i + 1, j + 1, robot);
        long long skip = 0 + solve(i, j + 1, robot);
        return dp[i][j] = min(take, skip);
    }
};