class Solution {
public:
    bool isCircularSentence(string sentence) {
        bool ok = true;
        vector<string> v;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            v.push_back(word);
        }
        int n = v.size();
        for (int i = 0; i < n; i++) {
            ok &= (v[i].back() == v[(i + 1) % n].front());
        }
        return ok;
    }
};