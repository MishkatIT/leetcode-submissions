class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string str;
        int n = searchWord.size();
        int cnt = 1;
        while (ss >> str) {
            if (str.substr(0, n) == searchWord) return cnt;
            cnt++;
        }
        return -1;
    }
};