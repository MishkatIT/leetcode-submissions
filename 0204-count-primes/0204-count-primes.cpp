class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n + 10, true);
        for (int i = 2 * 2; i <= n; i += 2)
        {
            prime[i] = false;
        }
        for (int i = 3; i * i <= n; i += 2)
        {
            if(prime[i])
            {
                for (int j = i * i; j <= n; j += i)
                    {
                        prime[j] = false;
                    }
            }
        }
        int ans = 0;
        for (int i = 2; i < n; i++)
        {
            if(prime[i])
                {
                    ans++;
                }
        }
        return ans;
    }
};