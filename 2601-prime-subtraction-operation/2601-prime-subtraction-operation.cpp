class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        const int N = 1000 + 5;
        vector<int> isPrime(N, true);
        for (int i = 2; i < N; i++) {
            if (isPrime[i]) {
                for (int j = i + i; j < N; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        vector<int> prime;
        for (int i = 2; i < N; i++) {
            if (isPrime[i]) {
                prime.push_back(i);
            }
        }
        int temp = nums.front();
        for (int i = 0; i < prime.size(); i++) {
            if (prime[i] < nums.front()) temp = nums.front() - prime[i];
        }
        nums.front() = temp;
        for (int i = 1; i < nums.size(); i++) {
            int temp = nums[i];
            for (int j = 0; j < prime.size(); j++) {
                if (prime[j] < nums[i] && nums[i] - prime[j] > nums[i - 1]) temp = nums[i] - prime[j];
                else break;
            }
            nums[i] = temp;
        }
        bool ok = true;
        for (int i = 0; i + 1 < nums.size(); i++) {
            ok &= (nums[i] < nums[i + 1]) ;
        }
        return ok;
    }
};