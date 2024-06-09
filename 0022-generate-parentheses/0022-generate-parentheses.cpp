class Solution {
public:
    vector<string> generateParenthesis(int n) {
        n *= 2;
        vector<string> ans;
        for (int i = 1; i < (1 << n); i++) {
            string temp;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    temp += '(';
                } else {
                    temp += ')';
                }
            }
            int stack = 0;
            bool ok = true;
            for (auto& i : temp) {
                if (i == '(') {
                    stack++;
                } else {
                    if (stack)
                        stack--;
                    else
                        ok = false;
                }
            }
            ok &= stack == 0;
            if (ok) {
                ans.push_back(temp);
            }
        }
        return ans;
    }
};