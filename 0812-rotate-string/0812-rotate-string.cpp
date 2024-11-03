class Solution {
public:
    bool rotateString(string s, string goal) {
        s += s;
        return s.find(goal) != string::npos && s.size() == goal.size();
    }
};