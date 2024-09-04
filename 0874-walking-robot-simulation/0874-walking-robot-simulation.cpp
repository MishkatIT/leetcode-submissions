class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        set<pair<int, int>> ob;
        for (auto& i : obstacles) {
            ob.insert({i[0], i[1]});
            ob.insert({i[1], i[0]});
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
            }
            if (x == -2) {
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
            cout << x << ' ' << y << ' ' << dir << endl;
            // cout << dir << ' ';
            if (dir == 'u') {
                while (i) {
                    if (haveOb(x, y)) {
                        y--; break;
                    }
                    y++, i--;
                    mx = max(mx, getMx(x, y));
                    // cout << mx << ' ';
                }
            }
            if (dir == 'r') {
                while (i) {
                    if (haveOb(x, y)) {
                        x--; break;
                    }
                    x++, i--;
                    mx = max(mx, getMx(x, y));
                    // cout << mx << ' ';
                }
            }
            if (dir == 'd') {
                while (i) {
                    if (haveOb(x, y)) {
                        y++; break;
                    }
                    y--, i--;
                    mx = max(mx, getMx(x, y));
                }
            }
            if (dir == 'l') {
                while (i) {
                    if (haveOb(x, y)) {
                        x++; break;
                    }
                    x--, i--;
                    mx = max(mx, getMx(x, y));
                }
            }
        }
        return mx;
    }
};