class Solution {
public:
    string compressedString(string word) {
        string comp;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            char cur = word[i];
            int cnt = 1;
            i++;
            while (i < n && cnt < 9) {
                if (word[i] != cur) break;
                cnt++;
                i++;
            }
            i--;
            comp += char(cnt + '0');
            comp += cur;
        }
        return comp;
    }
};