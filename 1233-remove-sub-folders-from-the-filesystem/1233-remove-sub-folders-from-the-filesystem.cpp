class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        map<string, bool> mp;
        vector<string> ans;
        for (int i = 0; i < folder.size(); i++) {
            string temp;
            bool have = false;
            folder[i] += "/";
            for (int j = 0; j < folder[i].size(); j++) {
                temp += folder[i][j];
                if (temp.back() == '/') {
                    temp.pop_back();
                    if (mp.find(temp) != mp.end()) {
                        have = true;
                        break;
                    }
                    temp += '/';
                }
            }
            if (!have) {
                temp.pop_back();
                mp[temp] = true;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};