class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        for (auto& c : s) {
            if (c != 'B' && c != 'D') {
                stk.push(c);
            } else {
                if (!stk.empty()) {
                    if (stk.top() == 'A' && c == 'B') stk.pop();
                    else if (stk.top() == 'C' && c == 'D') stk.pop();
                    else stk.push(c);
                } else stk.push(c);
            }
        }
        return stk.size();
    }
};