class Solution {
public:
    string fractionAddition(string expression) {
        if (expression.front() != '-') expression = "+" + expression;
        vector<pair<int, int>> x;
        for (int i = 0; i < expression.size(); ) {
            string temp;
            while (expression[i] != '/') temp += expression[i++];
            x.push_back({stoi(temp), 0});
            temp.clear();
            i++;
            while (i < expression.size() && (expression[i] != '-' && expression[i] != '+')) temp += expression[i++];
            x.back().second = stoi(temp);
        }

        auto getLcm = [&](int a, int b) {
            return a / __gcd(a, b) * b;
        };
        int lcm = x.front().second;
        for (auto& i : x) {
            lcm = getLcm(lcm, i.second);
        }
        int n  = 0;
        for (auto& i : x) {
            n += (lcm / i.second) * i.first;
        }
        int g = __gcd(n, lcm);
        n /= g, lcm /= g;
        if (lcm < 0) n *= -1, lcm *= -1; 
        string ans;
        ans += to_string(n);
        ans += "/";
        ans += to_string(lcm);
        return ans;
    }
};