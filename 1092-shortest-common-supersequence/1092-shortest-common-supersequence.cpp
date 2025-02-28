class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int a = str1.size(), b = str2.size();
        str1 = "#" + str1, str2 = "#" + str2; 
        vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));

        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                if (str1[i] == str2[j]) 
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        string scs = "";
        int i = a, j = b;
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && str1[i] == str2[j]) {
                scs += str1[i];
                i--, j--;
            } else if (j > 0 && (i == 0 || dp[i][j - 1] >= dp[i - 1][j])) {
                scs += str2[j];
                j--;
            } else {
                scs += str1[i];
                i--;
            }
        }

        reverse(scs.begin(), scs.end());
        return scs;
    }
};