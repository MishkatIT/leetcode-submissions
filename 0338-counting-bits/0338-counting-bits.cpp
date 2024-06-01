class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++)
        {
            int temp = i;
            for (int j = 0; j < 32; j++)
            {
                if(temp & 1)
                    ans[i]++;
                temp >>= 1;
            }
        }
        return ans;
    }
};