class Solution {
public:



   
        

        vector<int> sieve(int max_n) {
        vector<bool> is_prime(max_n + 1, true);
        vector<int> primes;
        
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= max_n; ++i) {
            if (is_prime[i]) {
                primes.push_back(i);
                for (int j = i * 1LL * i; j <= max_n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        return primes;
    }

    int nonSpecialCount(int l, int r) {
        int sqrtR = sqrt(r);
        vector<int> primes = sieve(sqrtR);
        int specialCount = 0;

        for (int prime : primes) {
            long long square = 1LL * prime * prime;
            if (square >= l && square <= r) {
                specialCount++;
            }
        }
        
        return (r - l + 1) - specialCount;
    }
};