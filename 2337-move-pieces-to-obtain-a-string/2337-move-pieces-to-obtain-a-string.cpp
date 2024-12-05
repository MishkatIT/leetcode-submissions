class Solution {
public:
    bool canChange(string start, string target) {
        string s1, s2;
        vector<int> posL1, posR1, posL2, posR2;

        for (int i = 0; i < start.size(); i++) {
            if (start[i] == 'L') posL1.push_back(i), s1 += 'L';
            else if (start[i] == 'R') posR1.push_back(i), s1 += 'R';

            if (target[i] == 'L') posL2.push_back(i), s2 += 'L';
            else if (target[i] == 'R') posR2.push_back(i), s2 += 'R';
        }

        if (s1 != s2) return false;

        for (int i = 0; i < posL1.size(); i++)
            if (posL1[i] < posL2[i]) return false; 

        for (int i = 0; i < posR1.size(); i++)
            if (posR1[i] > posR2[i]) return false; 

        return true;
    }
};
