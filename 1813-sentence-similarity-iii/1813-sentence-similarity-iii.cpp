class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> a, b;
        stringstream ss(sentence1), ss2(sentence2);
        string str;

        while (ss >> str) {
            a.push_back(str);
        }

        while (ss2 >> str) {
            b.push_back(str);
        }

        if (a.size() < b.size()) swap(a, b);

        int l = 0, r = 0;

        while (l < b.size() && a[l] == b[l]) {
            l++;
        }

        while (r < b.size() && a[a.size() - r - 1] == b[b.size() - r - 1]) {
            r++;
        }

        return l + r >= b.size();
    }
};
