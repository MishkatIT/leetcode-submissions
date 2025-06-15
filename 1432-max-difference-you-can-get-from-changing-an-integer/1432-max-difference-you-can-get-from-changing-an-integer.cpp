class Solution {
public:
    int maxDiff(int num) {
        string a = to_string(num);
        string b = a;
        char x = '9';

        for (auto& i : a) {
            if (i != '9') {
                x = i;
                break;
            }
        }
        for (auto& i : a) if (i == x) i = '9';
        x = b.front();
        if (b.front() != '1') {
            x = b.front();
            for (auto& i : b) {
                if (i == x) i = '1';
            }
        } else {
            x = -1;
            for (auto& i : b) {
                if (i != b.front() && i != '0') {
                    x = i;
                    break;
                }
            }
            for (int i = 1; i < b.size(); i++) {
                if (b[i] == x) b[i] = '0';
            }
        }
        return stoi(a) - stoi(b);
    }
};