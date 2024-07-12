class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char first = 'a', second = 'b';
        int point = x;
        if (x < y) {
            point = y;
            swap(first, second);
        }
        stack<char> stk;
        long long ans = 0;
        for (auto& i : s) {
            if (i == second) {
                if (!stk.empty() && stk.top() == first) {
                    ans += point;
                    stk.pop();
                } else {
                    stk.push(i);
                }
            } else {
                stk.push(i);
            }
        }
        swap(first, second);
        point = y;
        if (x < y) {
            point = x;
        }
        if (!stk.empty()) {
            char cur = stk.top();
            stk.pop();
            while (!stk.empty()) {
                if (stk.top() == first && cur == second) {
                    ans += point;
                }
                cur = stk.top();
                stk.pop();
            }
        }
        return ans;
    }
};