class Solution {
public:
    int buyChoco(vector<int>& v, int m) {
        sort(v.begin(), v.end());
        if(v[0] + v[1] > m) {
            return m;
        }
        else {
            return m - v[0] - v[1];
        }
    }
};