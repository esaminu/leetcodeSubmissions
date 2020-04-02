class Solution {
public:
    int countPrimes(int n) {
        int primeCount = 0;
        vector<int> primes(n,true);
        for(int i = 2; i*i < n; i++) {
            if(primes[i]) {
                for(int j = i * i; j <n; j+=i){
                    primes[j] = false;
                }
            }
        }
        
        for(int i = 2; i < n; i++) {
            if(primes[i]){
                primeCount++;
            }
        }
        return primeCount;
    }
};