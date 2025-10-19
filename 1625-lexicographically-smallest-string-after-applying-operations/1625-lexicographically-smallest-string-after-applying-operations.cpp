class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        set<string> vis;
        string ans = s;

        q.push(s);
        vis.insert(s);

        auto addOp = [&](string t) {
            for (int i = 1; i < (int)t.size(); i += 2)
                t[i] = ((t[i] - '0' + a) % 10) + '0';
            return t;
        };

        auto rotOp = [&](string t) {
            rotate(t.begin(), t.end() - b, t.end());
            return t;
        };

        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            ans = min(ans, cur);

            string x = addOp(cur);
            if (!vis.count(x)) {
                vis.insert(x);
                q.push(x);
            }

            string y = rotOp(cur);
            if (!vis.count(y)) {
                vis.insert(y);
                q.push(y);
            }
        }
        return ans;
    }
};
