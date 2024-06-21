class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        vector<int> original(n + 1), pref(n + 1);
        for (int i = 1; i <= n; i++) {
            original[i] = original[i - 1] + customers[i - 1] * !grumpy[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + customers[i - 1];
        }
        int ans = 0;
        for (int i = minutes; i <= n; i++) {
            ans = max(ans, pref[i] - pref[i - minutes] + original[n] - (original[i] - original[i - minutes]));
        }
        for (int i = 1; i <= n; i++) cout << original[i] << ' ';
        cout << endl;
        for (int i = 1; i <= n; i++) cout << pref[i] << ' ';
        cout << endl;
        return ans;
    }
};