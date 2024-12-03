class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int cur = spaces.front();
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (i == cur) {
                ans += ' ';
                j++;
                if (j < spaces.size()) cur = spaces[j];
            }
            ans += s[i];
        }
        return ans;
    }
};