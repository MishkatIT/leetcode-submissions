class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pref(n + 5);

        string vowel = "aeiou";
        auto ok = [&](string& str) {
            bool f = true;
            f &= (vowel.find(str.front()) != string::npos);
            f &= (vowel.find(str.back()) != string::npos);
            return f;
        };

        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + ok(words[i - 1]);
        }
        vector<int> ans;
        for (auto& i : queries) {
           ans.push_back(pref[i[1] + 1] - pref[i[0]]);
        }
        return ans;
    }
};