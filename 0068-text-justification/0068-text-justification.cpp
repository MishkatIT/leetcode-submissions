class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        for (int i = 0; i < n; ) {
            int j = i, wordLen = 0, space = 0, cnt = 0;
            while (j < n && wordLen + space + words[j].size() <= maxWidth) {
                wordLen += words[j].size();
                space++;
                j++;
                cnt++;
            }
            space = maxWidth - wordLen;
            cout << "space  " << space << '\n';
            int even = space / max(1, cnt - 1);
            int extra = space % max(1, cnt - 1);
            string temp;
            while (cnt > 0) {
                cnt--;
                temp += words[i++];
                if (temp.size() < maxWidth) {
                    temp += string(even, ' ');
                    if (extra > 0) {
                        extra--;
                        temp += " ";
                    }
                }
            }
            ans.push_back(temp);
            i = j;
        }
        string temp = ans.back();
        ans.pop_back();
        string x;
        char last = '#';
        for (auto& i : temp) {
            if (i == ' ') {
                if (last != ' ') x.push_back(' ');
            } else {
                x.push_back(i);
            }
            last = i;
        }
        x += string(maxWidth - x.size(), ' ');
        ans.push_back(x);
        return ans;
    }
};