class Solution {
public:
    bool judgeCircle(string moves) {
        int u = 0, r = 0;
        for (auto& i: moves) {
            if(i == 'U') u++;
            else if(i == 'D') u--;
            else if(i == 'R') r++;
            else if(i == 'L') r--;
        }
        if(u == 0 && r == 0)
            return true;
        else
            return false;
    }
};