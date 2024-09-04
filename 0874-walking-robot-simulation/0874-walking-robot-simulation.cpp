class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> ob;
        for (auto& i : obstacles) {
            ob.insert({i[0], i[1]});
        }

        auto haveOb = [&](int x, int y) {
            return (ob.find({x, y}) != ob.end());
        };

        auto fixDir = [&](int x, char dir) {
            if (x == -1) {
                if (dir == 'u') dir = 'r';
                else if (dir == 'r') dir = 'd';
                else if (dir == 'd') dir = 'l';
                else if (dir == 'l') dir = 'u';
            } else if (x == -2) {
                if (dir == 'u') dir = 'l';
                else if (dir == 'l') dir = 'd';
                else if (dir == 'd') dir = 'r';
                else if (dir == 'r') dir = 'u';
            }
            return dir;
        };

        auto getMx = [&](int x, int y) {
            return x * x + y * y;
        };

        int x = 0, y = 0;
        char dir = 'u';
        int mx = 0;
        for (auto& i : commands) {
            if (i < 0) {
                dir = fixDir(i, dir);
                continue;
            }

            int cur = i;
            if (dir == 'u') {
                while (cur) {
                    y++, cur--;
                    if (haveOb(x, y)) {
                        y--; 
                        break;
                    }
                    mx = max(mx, getMx(x, y));
                }
            } else if (dir == 'r') {
                while (cur) {
                    x++, cur--;
                    if (haveOb(x, y)) {
                        x--; 
                        break;
                    }
                    mx = max(mx, getMx(x, y));
                }
            } else if (dir == 'd') {
                while (cur) {
                    y--, cur--;
                    if (haveOb(x, y)) {
                        y++; 
                        break;
                    }
                    mx = max(mx, getMx(x, y));
                }
            } else if (dir == 'l') {
                while (cur) {
                    x--, cur--;
                    if (haveOb(x, y)) {
                        x++; 
                        break;
                    }
                    mx = max(mx, getMx(x, y));
                }
            }
        }
        return mx;
    }
};
