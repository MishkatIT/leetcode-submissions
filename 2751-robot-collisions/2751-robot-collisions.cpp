struct Node {
    int pos, health, dir, givenPos;
};
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Node> temp(n); // position, health, direction, intialPos
        for (int i = 0; i < n; i++) {
            temp[i] = {positions[i], healths[i], directions[i], i};
        }

        auto srt = [&](Node a, Node b) { return a.pos < b.pos; };

        sort(temp.begin(), temp.end(), srt);
        int cur = -1;
        stack<int> right;
        vector<bool> dead(n, false);
        for (int i = 0; i < n; i++) {
            if (cur == -1 && !right.empty()) {
                cur = right.top();
                right.pop();
            }
            if (temp[i].dir == 'R') {
                if (cur != -1) {
                    right.push(cur);
                }
                cur = i;
            } else {
                if (cur == -1)
                    continue;
                if (temp[cur].health < temp[i].health) {
                    temp[i].health--;
                    dead[cur] = true;
                    cur = -1;
                } else if (temp[cur].health > temp[i].health) {
                    temp[cur].health--;
                    dead[i] = true;
                } else {
                    dead[i] = dead[cur] = true;
                    cur = -1;
                }
            }
        }
        cur = -1;
        stack<int> left;
        for (int i = n - 1; i >= 0; i--) {
            if (dead[i]) continue;
            if (cur == -1 && !left.empty()) {
                cur = left.top();
                left.pop();
            }
            if (temp[i].dir == 'L') {
                if (cur != -1) {
                    left.push(cur);
                }
                cur = i;
            } else {
                if (cur == -1)
                    continue;
                if (temp[cur].health < temp[i].health) {
                    temp[i].health--;
                    dead[cur] = true;
                    cur = -1;
                } else if (temp[cur].health > temp[i].health) {
                    temp[cur].health--;
                    dead[i] = true;
                } else {
                    dead[i] = dead[cur] = true;
                    cur = -1;
                }
            }
        }
        vector<pair<int, int>> rem;
        for (int i = 0; i < n; i++) {
            if (!dead[i]) {
                rem.push_back({temp[i].givenPos, temp[i].health});
            }
        }
        sort(rem.begin(), rem.end());
        vector<int> ans;
        for (auto& i : rem) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
//  R R L L
//  15 10 10 12