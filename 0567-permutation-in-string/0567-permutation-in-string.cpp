class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> fa(26, 0), fb(26, 0);
        for (auto& i : s1) {
            fa[i - 'a']++;
        }
        for (int i = 0; i < s2.size(); i++) {
            if (i >= s1.size()) {
                fb[s2[i - s1.size()] - 'a']--;
            }
            fb[s2[i] - 'a']++;
            if (fa == fb) return true;
        }
        return false;
    }
};