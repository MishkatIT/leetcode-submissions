class Solution {
public:
    int countNegatives(vector<vector<int>>& x) {
        int neg = 0;
        for (int i = 0; i < (int)x.size(); i++){
            neg += upper_bound(x[i].rbegin(), x[i].rend(), -1) - x[i].rbegin();
        }
        return neg;        
    }
};