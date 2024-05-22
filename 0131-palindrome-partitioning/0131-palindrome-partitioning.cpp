class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> x;
        dfs(s, 0, x);
        return ans;
    }
    void dfs(string& str, int start, vector<string>& cur) {
        if (start == str.size()) {
            ans.push_back(cur);
        }
        for (int i = start; i < str.size(); i++) {
            if (isPalindrome(str, start, i)) {
                cur.push_back(str.substr(start, i - start + 1));
                dfs(str, i + 1, cur);
                cur.pop_back();
            }
        }
    }
    bool isPalindrome(string& str, int l, int r) {
        while (l <= r) {
            if (str[l] != str[r])
                return false;
            l++, r--;
        }
        return true;
    }
};