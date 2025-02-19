class Solution {
public:
    void gen(int n, int k, string &cur, vector<string> &res) {
        if (cur.size() == n) {
            res.push_back(cur);
            return;
        }
        
        for (char ch : {'a', 'b', 'c'}) {
            if (cur.empty() || cur.back() != ch) {
                cur.push_back(ch);
                gen(n, k, cur, res);
                cur.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> res;
        string cur;
        
        gen(n, k, cur, res);
        if (k > res.size()) {
            return "";
        }
        return res[k - 1];
    }
};
