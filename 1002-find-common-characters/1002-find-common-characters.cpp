class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        for (char i = 'a'; i <= 'z'; i++) {
            int cnt = 1e9;
            for (auto& j : words) {
                int temp = 0;
                for (auto& c : j) {
                    if (c == i) {
                        temp++;
                    }
                }
                cnt = min(temp, cnt);
            }
            while (cnt--) {
                ans.push_back(string(1, i));
            }
        }
        return ans;
    }
};