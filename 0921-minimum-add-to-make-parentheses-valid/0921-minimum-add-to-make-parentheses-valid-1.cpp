class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int ans = 0;
        for (auto& i : s) {
            if (i == ')') {
                if (!stk.empty()) {
                    stk.pop();
                } else {
                    ans++;
                }
            } else {
                stk.push(i);
            }
        }
        return ans + stk.size();
    }
};