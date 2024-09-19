class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return solve(0, expression);
    }
    vector<int> solve(int i, string expr) {
        vector<int > ans;
        for (int i = 0; i < expr.size(); i++) {
            if (!(expr[i] >= '0' && expr[i] <= '9')) {
                vector<int> left = solve(0, expr.substr(0, i));
                vector<int> right = solve(i + 1, expr.substr(i + 1)); 
                for (auto& a : left) {
                    for (auto& b : right) {
                        if (expr[i] == '+') {
                            ans.push_back(a + b);
                        }
                        if (expr[i] == '-') {
                            ans.push_back(a - b);
                        }
                        if (expr[i] == '*') {
                            ans.push_back(a * b);
                        }
                    }
                }
            } 
        }
        if (ans.size() == 0) ans.push_back(stoi(expr));
        return ans;
    }
};