class Solution {
public:
    string robotWithString(string s) {
        vector<int> f(26);
        for (auto& i : s) f[i - 'a']++;
        stack<char> stk;
        string ans;
        for (auto& i : s) {
            f[i - 'a']--;
            stk.push(i);
            while (!stk.empty()) {
                bool ok = true;
                for (int j = 0; j < stk.top() - 'a'; j++) {
                    if (f[j]) ok = false;
                }
                if (!ok) break;
                ans += stk.top();
                stk.pop();
            }
        }
        return ans;
    }
};