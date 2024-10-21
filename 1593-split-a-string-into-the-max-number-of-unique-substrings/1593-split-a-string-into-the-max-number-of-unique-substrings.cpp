class Solution {
public:
    int maxUniqueSplit(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < (1 << n); i++) {
            vector<int> temp(n);
            for (int j = 0; j < n; j++) {
                if ((1 << j) & i) {
                    temp[j] = 1;
                }
            }
            set<string> st;
            string x;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                x += s[i];
                if (temp[i] == 0) {
                    cnt++;
                    st.insert(x);
                    x.clear();
                } 
            }
            if (x.size()) {
                st.insert(x);
                cnt++;
            }
            if (st.size() == cnt) {
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};