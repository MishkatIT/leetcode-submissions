class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for (auto& dig : details) {
            string x;
            x += dig[11];
            x += dig[12];
            cnt += (stoi(x) > 60);
        }
        return cnt;
    }
};