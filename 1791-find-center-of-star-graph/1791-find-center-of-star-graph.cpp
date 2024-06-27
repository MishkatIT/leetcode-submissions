class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a = -1, b = -1;
        int ans;
        for (auto& i : edges) {
            if (i[0] == a || i[1] == a) ans = a;
            a = i[0];
            if (i[0] == b || i[1] == b) ans = b;
            b = i[1];
        }
        return ans;
    }
};