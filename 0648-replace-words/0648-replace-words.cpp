class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {

        map<string, bool> mp;
        for (auto& i : dictionary) {
            mp[i] = true;
        }

        stringstream ss(sentence);
        string str;
        string ans;
        while (ss >> str) {
            string temp;
            for (auto& i : str) {
                temp += i;
                if (mp[temp]) {
                    break;
                }
            }
            ans += temp;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};