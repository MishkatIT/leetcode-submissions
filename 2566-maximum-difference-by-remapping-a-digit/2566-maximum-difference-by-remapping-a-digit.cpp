class Solution {
public:
    int minMaxDifference(int num) {
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
        for (auto& i : b) if (i == x) i = '0';
        
        return stoi(a) - stoi(b);
    }
};