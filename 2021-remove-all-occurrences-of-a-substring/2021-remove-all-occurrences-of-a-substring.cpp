class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (true) {
            auto it = s.find(part);
            if (it == string::npos) break;
            s = s.substr(0, it) + s.substr(it + part.size());
        }
        return s;
    }
};