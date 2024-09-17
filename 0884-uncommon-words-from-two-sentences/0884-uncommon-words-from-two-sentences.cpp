class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        s1 += " " + s2;
        stringstream ss(s1);
        string x;
        map<string, int> mp;
        while (ss >> x) {
            mp[x]++;
        }
        vector<string> ans;
        for (auto& i : mp) {
            if (i.second == 1) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};