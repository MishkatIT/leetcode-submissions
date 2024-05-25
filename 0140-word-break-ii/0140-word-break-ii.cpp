class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> mp;
        for (auto& i : wordDict) {
            mp[i] = true;
        }
        vector<string> ans;
        int n = s.size();
        vector<string> cur;
        
         function<void(int)> all = [&](int i) {
            if (i == n) {
                string temp;
                for (auto& x : cur) {
                    temp += x;
                    temp += ' ';
                }
                temp.pop_back();
                ans.push_back(temp);
                return;
            }
            for (int j = i; j < n; j++) {
                string nxt = s.substr(i, j - i + 1);
                if (mp[nxt]) {
                    cur.push_back(nxt);
                    all(j + 1);
                    cur.pop_back();
                }
            }
        };

        all(0);
        return ans;
    }

};