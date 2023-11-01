class Solution {
public:
    int removeElement(vector<int>& v, int val) {
        int n = v.size();
        int l = 0, r = n - 1;
        while(l <= r) {
            if (v[l] == val) {
                while(r >= l && v[r] == val) r--;
                if(r >= l) {
                    swap(v[l], v[r]);
                    l++;
                }
            } else {
                l++;
            }
        }
        return l;
    }
};