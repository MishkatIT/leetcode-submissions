class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> mp;
        int pos = 0;
        mp = func(formula, pos);
        string ans;
        for (auto& i : mp) {
            ans += i.first;
            if (i.second != 1) {
                ans += to_string(i.second);
            }
        }
        return ans;
    }

    map<string, int> func(string& str, int& i) {
        map<string, int> mp;
        string temp;
        int n = str.size();
        while (i < n) {
            if (str[i] == ')') {
                i++;
                int dig = 0;
                while (i < n && str[i] >= '0' && str[i] <= '9') {
                    dig *= 10;
                    dig += (str[i] - '0');
                    i++;
                }
                for (auto& s : mp) {
                    s.second *= max(1, dig);
                }
                return mp;
            }
            if (i < n && str[i] >= '0' && str[i] <= '9') {
                int dig = 0;
                while (i < n && str[i] >= '0' && str[i] <= '9') {
                    dig *= 10;
                    dig += (str[i++] - '0');
                }
                mp[temp] += max(1, dig) - 1;
            }

            if (i < n && str[i] == '(') {
                i++;
                map<string, int> zz = func(str, i);
                for (auto& s : zz) {
                    mp[s.first] += s.second;
                }
            }

            if (i < n && str[i] >= 'A' && str[i] <= 'Z') {
                temp.clear();
                temp += str[i++];
                while (i < n && str[i] >= 'a' && str[i] <= 'z') {
                    temp += str[i++];
                }
                mp[temp]++;
            }
        }
        return mp;
    }
};