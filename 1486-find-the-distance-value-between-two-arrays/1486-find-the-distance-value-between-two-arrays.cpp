class Solution {
public:
    int findTheDistanceValue(vector<int>& a, vector<int>& b, int d) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            bool ok = true;
            for (int j = 0; j < b.size(); j++) {
                if(abs(a[i] - b[j]) <= d) {
                    ok = false;
                    break;
                }
            }
            cnt += ok;
        }
        return cnt;
    }
};