class Solution {
public:
    map<string, bool> mp;
    vector<int> dp;
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        for (auto& i : dictionary) {
            mp[i] = true;
        }
        dp.assign(n + 5, -1);
        return solve(0, s); 
    }
    int solve(int i, string& str) {
          if (i == str.size()) return 0;
          if (dp[i] != -1) return dp[i];
          int ans = 1 + solve(i + 1, str);
          string temp;
          for (int j = i; j < str.size(); j++) {
            temp += str[j];
            if (mp[temp]) {
                ans = min(ans, solve(j + 1, str));
            }
          }
          return dp[i] = ans;
    }
};