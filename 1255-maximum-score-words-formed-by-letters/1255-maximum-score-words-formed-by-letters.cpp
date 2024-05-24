class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> lett(26);
        for (auto& i : letters) {
            lett[i - 'a']++;
        }
        int n = words.size();
        int mx = 0;

        auto possible = [&](vector<int>& rem, string& str) {
            vector<int> temp(26);
            for (auto& i : str) {
                temp[i - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (rem[i] < temp[i]) {
                    return false;
                }
            }
            return true;
        };

        auto take = [&](vector<int>& rem, string& str) {
            int sum = 0;
            for (auto& i : str) {
                sum += score[i - 'a'];
                rem[i - 'a']--;
            }
            return sum;
        };

        for (int i = 0; i < (1 << n); i++) {
            int tmx = 0;
            vector<int> rem = lett;
            for (int j = 0; j < n; j++) {
                if ((1 << j) & i) {
                    if (possible(rem, words[j])) {
                        tmx += take(rem, words[j]);
                    }
                }
            }
            mx = max(mx, tmx);
        }
        return mx;
    }
};