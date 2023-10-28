class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cnt = 0, ans, x = 0;
        for  (int i = 1; i <= arr.back(); i++)
        {
            if(arr[x] != i)
            {
                cnt++;
                if(cnt == k)
                {
                    ans = i;
                    break;
                }
            }
            else x++;
        }
        if(cnt != k)
            ans = arr.back() + (k - cnt);
        return ans;
    }
};