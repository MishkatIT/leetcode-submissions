class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for (auto& i : details) {
            string x;
            x += i[11];
            x += i[12];
            cnt += (stoi(x) > 60);
        }
        return cnt;
    }
};