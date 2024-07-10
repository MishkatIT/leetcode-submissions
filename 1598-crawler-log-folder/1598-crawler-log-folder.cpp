class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (int i = 0; i < (int)logs.size(); i++) {
            if (logs[i] == "./") continue;
            else if (logs[i] == "../") ans--;
            else ans++;
            ans = max(0, ans);
        }
        return ans;
    }
};